#include "tensorflow/lite/delegates/vulkan/vulkan_delegate.h"
#include "tensorflow/lite/delegates/vulkan/vulkan_delegate_adaptor.h"
#include "tensorflow/lite/kernels/register.h"

#include <iostream>
#include "tensorflow/lite/c/common.h"

int main(int argc, char* argv[]) {
  std::cout << "Loading Linear model: y = 2x-1" << std::endl;
  std::unique_ptr<tflite::FlatBufferModel> model =
      tflite::FlatBufferModel::BuildFromFile("linear.tflite");

  if (!model) {
    std::cout << "Failed to mmap model" << std::endl;
    exit(0);
  }

  std::cout << "Creating Interpreter" << std::endl;
  tflite::ops::builtin::BuiltinOpResolver resolver;
  std::unique_ptr<tflite::Interpreter> interpreter;
  tflite::InterpreterBuilder(*model.get(), resolver)(&interpreter);

  std::cout << "Creating Delegate" << std::endl;
  VulkanDelegateOptions params = TfLiteVulkanOptionsDefault();
  auto* delegate_ptr = TfLiteVulkanDelegateCreate(&params);
  tflite::Interpreter::TfLiteDelegatePtr delegate(
      delegate_ptr,
      [](TfLiteDelegate* delegate) { TfLiteVulkanDelegateDelete(delegate); });

  std::cout << "Modifying Graph with delegate" << std::endl;
  interpreter->ModifyGraphWithDelegate(delegate.get());
  interpreter->AllocateTensors();

  std::cout << "Set input: x = 10" << std::endl;
  float* input = interpreter->typed_input_tensor<float>(0);
  // Dummy input for testing
  *input = 10.0;

  std::cout << "Invoke Inference" << std::endl;
  interpreter->Invoke();

  std::cout << "Get output" << std::endl;
  float* output = interpreter->typed_output_tensor<float>(0);
  std::cout << "Output: y = " << *output << std::endl;

  return 0;
}

