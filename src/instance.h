#ifndef _CYCLONE_INSTANCE_H_
#define _CYCLONE_INSTANCE_H_

#include <GLFW/glfw3.h>

typedef struct {
    GLFWwindow *window;
} c_instance_t;

void c_init_libs();
void c_free_libs();

void c_init(c_instance_t *c);
void c_free(c_instance_t *c);

void c_start(c_instance_t *c);
void c_end(c_instance_t *c);

#endif