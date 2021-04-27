#ifndef TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_
#define TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_

#include "tensorflow/lite/delegates/utils/simple_delegate.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

typedef struct {
    // Allowed ops to delegate.
    int allowed_builtin_code;
    // Report error during init.
    bool error_during_init;
    // Report error during prepare.
    bool error_during_prepare;
    // Report error during invoke.
    bool error_during_invoke;
} VulkanDelegateOptions;

#ifdef __cplusplus
}
#endif  // __cplusplus


namespace tflite{
namespace vulkan{

class VulkanDelegate : public SimpleDelegateInterface {
public:	
    explicit VulkanDelegate(const VulkanDelegateOptions& options)
       : options_(options) { }
    
    virtual bool IsNodeSupportedByDelegate(const TfLiteRegistration* registration,
        const TfLiteNode* node, TfLiteContext* context) const override
    {
        return false;
    }


    virtual const char* Name() const override  
    {
        return "Vulkan Delegate";
    }

    virtual SimpleDelegateInterface::Options DelegateOptions() const override
    {
        return SimpleDelegateInterface::Options();
    }

    virtual std::unique_ptr<SimpleDelegateKernelInterface> CreateDelegateKernelInterface() override;
    virtual TfLiteStatus Initialize(TfLiteContext* context) override;

private:
    const VulkanDelegateOptions options_;
};



} // namespace vulkan
} // namespace tflite


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif  // TENSORFLOW_LITE_DELEGATES_VULKAN_VULKAN_DELEGATE_KERNEL_H_