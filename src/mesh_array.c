#include <stdlib.h>

#include "mesh_array.h"
#include "memory.h"

void c_mesh_array_init(c_mesh_array_t *array)
{
    array->capacity = 0;
    array->count = 0;
    array->data = NULL;
}

void c_mesh_array_free(c_mesh_array_t *array)
{
    for (int i = 0; i < array->count; ++i) {
        c_mesh_free(&array->data[i]);
    }

    C_FREE_ARRAY(c_mesh_t, array->data, array->capacity);
    c_mesh_array_init(array);
}

void c_mesh_array_push(c_mesh_array_t *array, c_mesh_t *mesh)
{
    if (array->count + 1 > array->capacity) {
        int old_capacity = array->capacity;
        array->capacity = C_GROW_CAPACITY(old_capacity);
        array->data = C_GROW_ARRAY(c_mesh_t, array->data, old_capacity, array->capacity);
    }

    array->data[array->count++] = *mesh;
}