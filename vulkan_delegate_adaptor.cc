#include "vulkan_delegate_adaptor.h"

VulkanDelegateOptions TfLiteVulkanOptionsDefault()
{
    VulkanDelegateOptions Options = {0};
    return Options;
}

TfLiteDelegate* TfLiteVulkanDelegateCreate(const VulkanDelegateOptions* options)
{
    std::unique_ptr<tflite::vulkan::VulkanDelegate> newVulkanDelegate(
       new tflite::vulkan::VulkanDelegate(options ? * options : TfLiteVulkanOptionsDefault()));
    return tflite::TfLiteDelegateFactory::CreateSimpleDelegate(std::move(newVulkanDelegate));
}

void TfLiteVulkanDelegateDelete(TfLiteDelegate* delegate){
    tflite::TfLiteDelegateFactory::DeleteSimpleDelegate(delegate);
}
