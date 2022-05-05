#ifndef _CYCLONE_MESH_ARRAY_H_
#define _CYCLONE_MESH_ARRAY_H_

#include "mesh.h"

typedef struct {
    int capacity;
    int count;
    c_mesh_t *data;
} c_mesh_array_t;

void c_mesh_array_init(c_mesh_array_t *array);
void c_mesh_array_free(c_mesh_array_t *array);
void c_mesh_array_push(c_mesh_array_t *array, c_mesh_t *mesh);

#endif