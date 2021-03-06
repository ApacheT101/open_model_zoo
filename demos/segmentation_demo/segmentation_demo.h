// Copyright (C) 2018-2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <string>
#include <vector>
#include <gflags/gflags.h>
#include <iostream>

static const char help_message[] = "Print a usage message.";
static const char image_message[] = "Required. Path to a .bmp image.";
static const char model_message[] = "Required. Path to an .xml file with a trained model.";\
static const char target_device_message[] = "Optional. Specify the target device to infer on (the list of available devices is shown below). " \
                                            "Default value is CPU. Use \"-d HETERO:<comma-separated_devices_list>\" format to specify HETERO plugin. " \
                                            "The demo will look for a suitable plugin for a specified device.";
static const char custom_cldnn_message[] = "Required for GPU custom kernels. "\
                                           "Absolute path to the .xml file with the kernels descriptions.";
static const char custom_cpu_library_message[] = "Required for CPU custom layers. " \
                                                 "Absolute path to a shared library with the kernels implementations.";
static const char config_message[] = "Path to the configuration file. Default value: \"config\".";

DEFINE_string(c, "", custom_cldnn_message);
DEFINE_string(l, "", custom_cpu_library_message);
DEFINE_bool(h, false, help_message);
DEFINE_string(i, "", image_message);
DEFINE_string(m, "", model_message);
DEFINE_string(d, "CPU", target_device_message);
DEFINE_string(config, "", config_message);


/**
* @brief This function show a help message
*/
static void showUsage() {
    std::cout << std::endl;
    std::cout << "segmentation_demo [OPTION]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << std::endl;
    std::cout << "    -h                        " << help_message << std::endl;
    std::cout << "    -i \"<path>\"               " << image_message << std::endl;
    std::cout << "    -m \"<path>\"               " << model_message << std::endl;
    std::cout << "      -l \"<absolute_path>\"    " << custom_cpu_library_message << std::endl;
    std::cout << "          Or" << std::endl;
    std::cout << "      -c \"<absolute_path>\"    " << custom_cldnn_message << std::endl;
    std::cout << "    -d \"<device>\"             " << target_device_message << std::endl;
}
