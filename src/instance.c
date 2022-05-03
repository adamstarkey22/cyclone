#include <glad/gl.h>

#include "instance.h"

void c_init(c_instance_t *c)
{
    c->window = glfwCreateWindow(640, 480, "cyclone", NULL, NULL);
    glfwMakeContextCurrent(c->window);
    gladLoadGL(glfwGetProcAddress);

    c_quad_init(&c->quad);
}

void c_free(c_instance_t *c)
{
    c_quad_free(&c->quad);
    glfwDestroyWindow(c->window);
}

int c_shouldclose(c_instance_t *c)
{
    return glfwWindowShouldClose(c->window);
}