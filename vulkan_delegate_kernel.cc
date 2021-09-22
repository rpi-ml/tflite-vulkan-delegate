#include "vulkan_delegate_kernel.h"

namespace tflite {
namespace vulkan {

TfLiteStatus VulkanKernel::Init(TfLiteContext* context,
                                const TfLiteDelegateParams* params) {
  return kTfLiteOk;
}

TfLiteStatus VulkanKernel::Prepare(TfLiteContext* context, TfLiteNode* node) {
  return kTfLiteOk;
}

TfLiteStatus VulkanKernel::Eval(TfLiteContext* context, TfLiteNode* node) {
  return kTfLiteOk;
}

}  // namespace vulkan
}  // namespace tflite

