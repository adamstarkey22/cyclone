#include <stdio.h>
#include <stdlib.h>

#include "internal.h"

CInstance *c_create_instance()
{
    CInstance *instance = (CInstance *)malloc(sizeof(CInstance));
    if (instance) {
        instance->window = glfwCreateWindow(640, 480, "cyclone", NULL, NULL);
        if (instance->window) {
            glfwMakeContextCurrent(instance->window);
            if (gladLoadGL(glfwGetProcAddress)) {
                c_init_mesh_array(&instance->meshes);
                c_init_program_array(&instance->programs);
                return instance;
            }
            glfwDestroyWindow(instance->window);
        }
        free(instance);
    }
    return NULL;
}

void c_destroy_instance(CInstance *instance)
{
    c_free_mesh_array(&instance->meshes);
    c_free_program_array(&instance->programs);
    glfwDestroyWindow(instance->window);
    free(instance);
}

int c_create_mesh(CInstance *instance, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    CMesh mesh;
    c_init_mesh(&mesh, vertex_count, vertices, element_count, elements);
    return c_push_mesh(&instance->meshes, mesh);
}

int c_create_program(CInstance *instance, const char *vertex_shader_source, const char *fragment_shader_source)
{
    CProgram program;
    c_init_program(&program, vertex_shader_source, fragment_shader_source);
    return c_push_program(&instance->programs, program);
}