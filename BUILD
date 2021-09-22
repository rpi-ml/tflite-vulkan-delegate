
cc_library(
    name = "vulkan_delegate",
    srcs = [
        "vulkan_delegate.cc",
        "vulkan_delegate_kernel.cc",
    ],
    hdrs = [
        "vulkan_delegate.h",
        "vulkan_delegate_kernel.h",
    ],
    deps = [
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/delegates/utils:simple_delegate",
    ],
)

cc_binary(
    name = "vulkan_delegate.so",
    srcs = [
        "vulkan_delegate_adaptor.h",
        "vulkan_delegate_adaptor.cc",
    ],
    linkshared = 1,
    linkstatic = 1,
    deps = [
        ":vulkan_delegate",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/tools:command_line_flags",
        "//tensorflow/lite/tools:logging",
    ],
)