#ifndef CYCLONE_INTERNAL_H
#define CYCLONE_INTERNAL_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../include/cyclone/cyclone.h"

typedef struct CMesh CMesh;
typedef unsigned CProgram;
typedef struct CMeshArray CMeshArray;
typedef struct CProgramArray CProgramArray;

struct CMesh {
    unsigned vertex_array_object;
    unsigned vertex_buffer;
    unsigned element_buffer;
    int element_count;
};

struct CMeshArray {
    int capacity;
    CMesh *data;
};

struct CProgramArray {
    int capacity;
    CProgram *data;
};

struct CInstance {
    GLFWwindow *window;
    CMeshArray meshes;
    CProgramArray programs;
};

void c_init_mesh(CMesh *mesh, int vertex_count, float *vertices, int element_count, unsigned *elements);
void c_free_mesh(CMesh *mesh);
void c_zero_mesh(CMesh *mesh);

void c_init_program(CProgram *program, const char *vertex_shader_source, const char *fragment_shader_source);
void c_free_program(CProgram *program);
void c_zero_program(CProgram *program);

void c_init_mesh_array(CMeshArray *array);
void c_free_mesh_array(CMeshArray *array);
int c_push_mesh(CMeshArray *array, CMesh mesh);
void c_erase_mesh(CMeshArray *array, int index);

void c_init_program_array(CProgramArray *array);
void c_free_program_array(CProgramArray *array);
int c_push_program(CProgramArray *array, CProgram program);
void c_erase_program(CProgramArray *array, int index);

#endif