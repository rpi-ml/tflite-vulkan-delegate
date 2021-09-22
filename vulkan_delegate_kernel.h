#ifndef TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_
#define TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_

#include "tensorflow/lite/delegates/utils/simple_delegate.h"
#include "vulkan_delegate.h"

namespace tflite {
namespace vulkan {

class VulkanKernel : public SimpleDelegateKernelInterface {
 public:
  explicit VulkanKernel(const VulkanDelegateOptions& options)
      : options_(options) {}

  TfLiteStatus Init(TfLiteContext* context,
                    const TfLiteDelegateParams* params) override;

  TfLiteStatus Prepare(TfLiteContext* context, TfLiteNode* node) override;

  TfLiteStatus Eval(TfLiteContext* context, TfLiteNode* node) override;

 private:
  const VulkanDelegateOptions options_;
};

}  // namespace vulkan
}  // namespace tflite

#endif  // TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_
