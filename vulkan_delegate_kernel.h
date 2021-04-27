#ifndef TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_H_
#define TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_H_

#include "vulkan_delegate.h"
#include "tensorflow/lite/delegates/utils/simple_delegate.h"

namespace tflite{
namespace vulkan{

class VulkanKernel : public SimpleDelegateKernelInterface {

public:

    explicit VulkanKernel(const VulkanDelegateOptions& options)
      : options_(options) {}

    TfLiteStatus Init(TfLiteContext* context, const TfLiteDelegateParams* params) override;

    TfLiteStatus Prepare(TfLiteContext* context, TfLiteNode* node) override;

    TfLiteStatus Eval(TfLiteContext* context, TfLiteNode* node) override;

private:

    const VulkanDelegateOptions options_;
};


} // namespace vulkan
} // namespace tflite

#endif  // TENSORFLOW_LITE_DELEGATES_HEXAGON_HEXAGON_DELEGATE_H_