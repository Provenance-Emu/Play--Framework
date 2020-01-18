#pragma once

#include <vulkan/vulkan.h>
#include "maybe_unused.h"

#define DECLARE_STRUCT(structName, structId) FRAMEWORK_MAYBE_UNUSED static Vk##structName structName() { Vk##structName result = { structId }; return result; }

namespace Framework
{
	namespace Vulkan
	{
		DECLARE_STRUCT(ApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO)
		DECLARE_STRUCT(BufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO)
		DECLARE_STRUCT(ComputePipelineCreateInfo, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO)
		DECLARE_STRUCT(CommandBufferAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO)
		DECLARE_STRUCT(CommandBufferBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO)
		DECLARE_STRUCT(CommandPoolCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO)
		DECLARE_STRUCT(DescriptorPoolCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO);
		DECLARE_STRUCT(DescriptorSetAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO);
		DECLARE_STRUCT(DescriptorSetLayoutCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO)
		DECLARE_STRUCT(DeviceQueueCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO)
		DECLARE_STRUCT(DeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO)
		DECLARE_STRUCT(FenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO)
		DECLARE_STRUCT(FramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO)
		DECLARE_STRUCT(GraphicsPipelineCreateInfo, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO)
		DECLARE_STRUCT(ImageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO)
		DECLARE_STRUCT(ImageMemoryBarrier, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER)
		DECLARE_STRUCT(ImageViewCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO)
		DECLARE_STRUCT(InstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO)
		DECLARE_STRUCT(MemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO)
		DECLARE_STRUCT(PipelineCacheCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO)
		DECLARE_STRUCT(PipelineColorBlendStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineDepthStencilStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineDynamicStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineInputAssemblyStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO)
		DECLARE_STRUCT(PipelineMultisampleStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineRasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineVertexInputStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO)
		DECLARE_STRUCT(PipelineViewportStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO)
		DECLARE_STRUCT(RenderPassBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO)
		DECLARE_STRUCT(RenderPassCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO)
		DECLARE_STRUCT(SamplerCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO)
		DECLARE_STRUCT(SemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO)
		DECLARE_STRUCT(ShaderModuleCreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO)
		DECLARE_STRUCT(SubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO)
		DECLARE_STRUCT(WriteDescriptorSet, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET)
		
		//VK_EXT_debug_report
		DECLARE_STRUCT(DebugReportCallbackCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT)

		//VK_EXT_fragment_shader_interlock
		DECLARE_STRUCT(PhysicalDeviceFragmentShaderInterlockFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT)

		//VK_KHR_get_physical_device_properties2
		DECLARE_STRUCT(PhysicalDeviceFeatures2KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR)

		//VK_KHR_swapchain
		DECLARE_STRUCT(PresentInfoKHR, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR)
		DECLARE_STRUCT(SwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR)
		
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
		//VK_KHR_android_surface
		DECLARE_STRUCT(AndroidSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR)
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
		//VK_KHR_xcb_surface
		DECLARE_STRUCT(XcbSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR);
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
		//VK_KHR_win32_surface
		DECLARE_STRUCT(Win32SurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR);
#endif
	}
}

#undef DECLARE_STRUCT
