#include "http/AndroidHttpClient.h"
#include "http/java_net_URL.h"
#include "http/java_net_HttpURLConnection.h"
#include "http/java_io_InputStream.h"
#include "android/JavaVM.h"

using namespace Framework;
using namespace Framework::Http;

struct ScopedDisconnecter
{
public:
	ScopedDisconnecter(java::net::HttpURLConnection& connection)
		: m_connection(connection)
	{
		
	}
	
	~ScopedDisconnecter()
	{
		m_connection.disconnect();
	}
	
private:
	java::net::HttpURLConnection& m_connection;
};

RequestResult CAndroidHttpClient::SendRequest()
{
	auto env = CJavaVM::GetEnv();
	
	auto url = java::net::URL(env->NewStringUTF(m_url.c_str()));
	auto connection = CJavaObject::CastTo<java::net::HttpURLConnection>(url.openConnection());

	{
		ScopedDisconnecter disconnecter(connection);

		RequestResult result;
		result.statusCode = static_cast<HTTP_STATUS_CODE>(connection.getResponseCode());

		auto inputStream = 
			[&] ()
			{
				uint32 resultClass = static_cast<uint32>(result.statusCode) / 100;
				switch(resultClass)
				{
				case 4:
				case 5:
					return CJavaObject::CastTo<java::io::InputStream>(connection.getErrorStream());
				default:
					return CJavaObject::CastTo<java::io::InputStream>(connection.getInputStream());
				}
			}();

		static const int bufferSize = 0x10000;
		std::vector<jbyte> buffer;
		buffer.resize(bufferSize);

		while(1)
		{
			auto readResult = inputStream.read(buffer);
			if(readResult == -1)
			{
				break;
			}
			result.data.Write(buffer.data(), readResult);
		}
		
		return result;
	}
}
