#ifndef _CYCLONE_INSTANCE_H_
#define _CYCLONE_INSTANCE_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "mesh.h"

typedef struct {
    GLFWwindow *window;
    c_mesh_t quad_mesh;
} c_instance_t;

void c_init(c_instance_t *c);
void c_free(c_instance_t *c);

#endif