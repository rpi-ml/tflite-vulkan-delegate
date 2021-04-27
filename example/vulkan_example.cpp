#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/delegates/vulkan/vulkan_delegate.h"
#include "tensorflow/lite/delegates/vulkan/vulkan_delegate_adaptor.h"

#include "tensorflow/lite/c/common.h"

int main(int argc, char* argv[])
{
    printf("Loading Linear model: y = 2x-1\n");
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile("linear.tflite");

    if(!model){
        printf("Failed to mmap model\n");
        exit(0);
    }

    printf("Creating Interpreter\n");
    tflite::ops::builtin::BuiltinOpResolver resolver;
    std::unique_ptr<tflite::Interpreter> interpreter;
    tflite::InterpreterBuilder(*model.get(), resolver)(&interpreter);

    printf("Creating Delegate\n");
    VulkanDelegateOptions params = TfLiteVulkanOptionsDefault();
    auto* delegate_ptr = TfLiteVulkanDelegateCreate(&params);

    tflite::Interpreter::TfLiteDelegatePtr delegate(delegate_ptr,
    [](TfLiteDelegate* delegate) {
       TfLiteVulkanDelegateDelete(delegate);
    });

    printf("Modifying Graph with delegate\n");
    interpreter->ModifyGraphWithDelegate(delegate.get());
    interpreter->AllocateTensors();

    printf("Set input: x = 10\n");
    float* input = interpreter->typed_input_tensor<float>(0);
    // Dummy input for testing
    *input = 10.0;

    printf("Invoke Inference\n");
    interpreter->Invoke();

    float* output = interpreter->typed_output_tensor<float>(0);

    printf("Output: y = %f\n", *output);

    return 0;
}
