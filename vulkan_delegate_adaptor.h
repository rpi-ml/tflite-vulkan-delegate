#ifndef TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_ADAPTOR_H_
#define TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_ADAPTOR_H_

#include "vulkan_delegate.h"
#include "vulkan_delegate_kernel.h"
#include "tensorflow/lite/c/common.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

// Returns a structure with the default delegate options.
VulkanDelegateOptions TfLiteVulkanOptionsDefault();

// Creates a new delegate instance that needs to be destroyed with
// `TfLiteVulkanDelegateDelete` when delegate is no longer used by TFLite.
// When `options` is set to `nullptr`, the above default values are used:
TfLiteDelegate* TfLiteVulkanDelegateCreate(const VulkanDelegateOptions* options);

// Destroys a delegate created with `TfLiteVulkanDelegateCreate` call.
void TfLiteVulkanDelegateDelete(TfLiteDelegate* delegate);

#ifdef __cplusplus
}
#endif  // __cplusplus

// A convenient wrapper that returns C++ std::unique_ptr for automatic memory
// management.
inline std::unique_ptr<TfLiteDelegate, void (*)(TfLiteDelegate*)>
TfLiteVulkanDelegateCreateUnique(const VulkanDelegateOptions* options) {
    return std::unique_ptr<TfLiteDelegate, void (*)(TfLiteDelegate*)>(
      TfLiteVulkanDelegateCreate(options), TfLiteVulkanDelegateDelete);
}

#endif  // TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_ADAPTOR_H_
