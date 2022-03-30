//
// Created by zhanghong50 on 2022/1/21.
//

#ifndef MYENGINE_WINDOW_PREDECLARED_H
#define MYENGINE_WINDOW_PREDECLARED_H

#include <stdio.h>
#include <string>
#include <vector>
#include <filesystem>
#include <mutex>
#include <condition_variable>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

namespace window {

static std::string SceneTreeRootName = "Scene Root";

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

}

#endif //MYENGINE_WINDOW_PREDECLARED_H
