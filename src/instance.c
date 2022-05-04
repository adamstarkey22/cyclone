#include <glad/gl.h>

#include "instance.h"

const float quad_vertices[] = { 0.0f };
const unsigned quad_elements[] = { 0, 1, 2, 0, 2, 3 };

void c_init(c_instance_t *c)
{
    c->window = glfwCreateWindow(640, 480, "cyclone", NULL, NULL);
    glfwMakeContextCurrent(c->window);
    gladLoadGL(glfwGetProcAddress);

    c_mesh_init(&c->quad_mesh, 0, quad_vertices, 6, quad_elements);
}

void c_free(c_instance_t *c)
{
    c_mesh_free(&c->quad_mesh);
    glfwDestroyWindow(c->window);
}

int c_shouldclose(c_instance_t *c)
{
    return glfwWindowShouldClose(c->window);
}