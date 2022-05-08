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
    _c_init_program_array(&instance->programs);
    return instance;
}

void c_destroy_instance(c_instance_t *instance)
{
    _c_mesh_array_free(&instance->meshes);
    _c_free_program_array(&instance->programs);
    glfwDestroyWindow(instance->window);
    free(instance);
}

unsigned c_create_mesh(c_instance_t *instance, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    return _c_mesh_array_create_mesh(&instance->meshes, vertex_count, vertices, element_count, elements);
}

unsigned c_create_program(c_instance_t *instance, const char *vertex_shader_source, const char *fragment_shader_source)
{
    return _c_create_program(&instance->programs, vertex_shader_source, fragment_shader_source);
}

void c_destroy_program(c_instance_t *instance, unsigned id)
{
    _c_destroy_program(&instance->programs, id);
}