#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "init.h"

static void error_callback(int error_code, const char *description)
{
    fprintf(stderr, "GLFW error: %s\n", description);
}

void c_init_lib()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void c_free_lib()
{
    glfwTerminate();
}