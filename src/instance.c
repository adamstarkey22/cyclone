#include <stdio.h>
#include <stdlib.h>

#include "instance.h"

c_instance_t *c_create_instance()
{
    c_instance_t *instance = (c_instance_t *)malloc(sizeof(c_instance_t));
    if (instance == NULL) return NULL;

    instance->window = glfwCreateWindow(640, 480, "cyclone", NULL, NULL);
    if (instance->window == NULL) {
        free(instance);
        return NULL;
    }

    glfwMakeContextCurrent(instance->window);
    if (!gladLoadGL(glfwGetProcAddress)) {
        glfwDestroyWindow(instance->window);
        free(instance);
        return NULL;
    }

    _c_mesh_array_init(&instance->meshes);
    return instance;
}

void c_destroy_instance(c_instance_t *instance)
{
    _c_mesh_array_free(&instance->meshes);
    glfwDestroyWindow(instance->window);
    free(instance);
}

unsigned c_create_mesh(c_instance_t *instance, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    return _c_mesh_array_create_mesh(&instance->meshes, vertex_count, vertices, element_count, elements);
}