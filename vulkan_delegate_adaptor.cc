#include "vulkan_delegate_adaptor.h"

VulkanDelegateOptions TfLiteVulkanOptionsDefault() {
  VulkanDelegateOptions options = {0};
  return options;
}

TfLiteDelegate* TfLiteVulkanDelegateCreate(
    const VulkanDelegateOptions* options) {
  std::unique_ptr<tflite::vulkan::VulkanDelegate> newVulkanDelegate(
      new tflite::vulkan::VulkanDelegate(
          options ? *options : TfLiteVulkanOptionsDefault()));
  return tflite::TfLiteDelegateFactory::CreateSimpleDelegate(
      std::move(newVulkanDelegate));
}

void TfLiteVulkanDelegateDelete(TfLiteDelegate* delegate) {
  tflite::TfLiteDelegateFactory::DeleteSimpleDelegate(delegate);
}

