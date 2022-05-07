#ifndef _CYCLONE_INSTANCE_H_
#define _CYCLONE_INSTANCE_H_

#include <cyclone/cyclone.h>
#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

#include "mesh_array.h"

struct c_instance_t {
    GLFWwindow *window;
    _c_mesh_array_t meshes;
};

#endif