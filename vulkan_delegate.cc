#include "vulkan_delegate.h"
#include "vulkan_delegate_kernel.h"

namespace tflite{
namespace vulkan{

TfLiteStatus VulkanDelegate::Initialize(TfLiteContext* context) 
{
	return kTfLiteOk;
}

std::unique_ptr<SimpleDelegateKernelInterface> VulkanDelegate::CreateDelegateKernelInterface() 
{
    return make_unique<VulkanKernel>(options_);
}

} // namespace vulkan
} // namespace tflite
