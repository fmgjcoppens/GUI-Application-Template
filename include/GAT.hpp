#pragma once

#include <cstdint>
#include <vulkan/vulkan_core.h>
#include <stdlib.h>         // abort
#include "imgui.h"
#include "imgui_impl_vulkan.h"
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Volk headers
#ifdef IMGUI_IMPL_VULKAN_USE_VOLK
#define VOLK_IMPLEMENTATION
#include <volk.h>
#endif

//#define APP_USE_UNLIMITED_FRAME_RATE
#ifdef _DEBUG
#define APP_USE_VULKAN_DEBUG_REPORT
VkDebugReportCallbackEXT g_DebugReport;
#endif

#ifdef APP_USE_VULKAN_DEBUG_REPORT
VKAPI_ATTR VkBool32 VKAPI_CALL debug_report(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData)
{
    (void)flags; (void)object; (void)location; (void)messageCode; (void)pUserData; (void)pLayerPrefix; // Unused arguments
    fprintf(stderr, "[vulkan] Debug report from ObjectType: %i\nMessage: %s\n\n", objectType, pMessage);
    return VK_FALSE;
}
#endif // APP_USE_VULKAN_DEBUG_REPORT

void glfw_error_callback(int error, const char* description);

void check_vk_result(VkResult err);

bool IsExtensionAvailable(const ImVector<VkExtensionProperties>& properties, const char* extension);

VkPhysicalDevice SetupVulkan_SelectPhysicalDevice(VkInstance& g_Instance);

void SetupVulkan(VkInstance& g_Instance, ImVector<const char*> instance_extensions, VkAllocationCallbacks* g_Allocator, VkPhysicalDevice& g_PhysicalDevice, uint32_t& g_QueueFamily, VkDevice& g_Device, VkQueue& g_Queue, VkDescriptorPool& g_DescriptorPool);

// All the ImGui_ImplVulkanH_XXX structures/functions are optional helpers used by the demo.
// Your real engine/app may not use them.
void SetupVulkanWindow(VkInstance& g_Instance, ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height, VkAllocationCallbacks* g_Allocator, VkPhysicalDevice& g_PhysicalDevice, uint32_t& g_QueueFamily, VkDevice& g_Device, int g_MinImageCount);

void CleanupVulkan(VkInstance& g_Instance, VkAllocationCallbacks* g_Allocator, VkDevice& g_Device, VkDescriptorPool& g_DescriptorPool);

void CleanupVulkanWindow(VkInstance& g_Instance, VkAllocationCallbacks* g_Allocator, VkDevice& g_Device, ImGui_ImplVulkanH_Window g_MainWindowData);

void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data, VkDevice& g_Device, VkQueue& g_Queue, bool g_SwapChainRebuild);

void FramePresent(ImGui_ImplVulkanH_Window* wd, VkQueue& g_Queue, bool g_SwapChainRebuild);
