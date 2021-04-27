# Vulkan Delegate for TensorFlow Lite

## Build TensorFlow Lite

The first step for using the Vulkan Delegate for TensorFlow Lite is to download the TensorFlow repository and build tflite succesfully. [Here](https://developer.ridgerun.com/wiki/index.php?title=How_to_Install_TensorFlow_Lite) you can find a complete guide of how to build TensorFlow Lite. Please make sure to install the v2.4.0 version (or any more recent than this), because older versions may not include the required support for custom delegates. Also, the bazel version obtained through the guide may be wrong, for example, to build tensorflow v2.4.0 it is needed bazel v3.99.0.

After creating the static library of tensorflowlite, make sure to copy it to the local libraries folder (execute the following from the root folder of the tensorflow repository)

    sudo cp tensorflow/lite/tools/make/gen/linux_x86_64/lib/libtensorflow-lite.a /usr/local/lib/


## Build Vulkan Delegate dynamic library

Include the vulkan delegate repository to TensorFlow by cloning the it to the delegates folder. 
From the root folder of TensorFlow repository

    cd tensorflow/lite/delegates
    git clone https://github.com/rpi-ml/tflite-vulkan-delegate.git

Build the dynamic library using bazel

    cd ../../..
    bazel build -c opt tensorflow/lite/delegates/tflite-vulkan-delegate:vulkan_delegate.so

The library will be built here
    
    realpath bazel-bin/tensorflow/lite/delegates/tflite-vulkan-delegate/vulkan_delegate.so

## Build and Execute example with delegate

Go the example folder on the vulkan delegate repository

    cd tensorflow/lite/delegates/tflite-vulkan-delegate/example

Build the example using the makefile

    make

Execute the example

    ./vulkan_example