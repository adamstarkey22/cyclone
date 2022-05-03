#ifndef _CYCLONE_INSTANCE_H_
#define _CYCLONE_INSTANCE_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "quad.h"

typedef struct {
    GLFWwindow *window;
    c_quad_t quad;
} c_instance_t;

void c_init(c_instance_t *c);
void c_free(c_instance_t *c);

int c_shouldclose(c_instance_t *c);

#endif