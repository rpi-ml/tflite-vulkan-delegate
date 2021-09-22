TF_PATH = $(PWD)/../../../../..
DELEGATE_LIB = $(TF_PATH)/bazel-bin/tensorflow/lite/delegates/tflite-vulkan-delegate/vulkan_delegate.so

CXXFLAGS = -DCK_HOST_OS_NAME2_LINUX=1 -DCK_HOST_OS_NAME_LINUX=1 -DCK_TARGET_OS_NAME2_LINUX=1 -DCK_TARGET_OS_NAME_LINUX=1 -std=c++11 -DTF_LITE_1_13 -Wall -Wno-sign-compare -Wno-psabi 
CXXINC = -I$(TF_PATH) -I$(TF_PATH)/tensorflow/lite/tools/make/downloads/flatbuffers/include -I$(TF_PATH)tensorflow/lite/tools/make/downloads/absl
CXXLIB = -L/usr/local/lib -pthread -ltensorflow-lite -ldl -latomic -lrt $(DELEGATE_LIB)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINC) $< -o $@

vulkan_example : vulkan_example.o
	$(CXX) $< -o $@ $(CXXLIB)

clean:
	rm -f *.o
