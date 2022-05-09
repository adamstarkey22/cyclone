#include "internal.h"
#include "memory.h"

void c_init_mesh_array(CMeshArray *array)
{
    array->capacity = 0;
    array->data = NULL;
}

void c_free_mesh_array(CMeshArray *array)
{
    for (int i = 0; i < array->capacity; ++i) {
        if (array->data[i].vertex_array_object != 0) {
            c_free_mesh(&array->data[i]);
        }
    }

    FREE_ARRAY(CMesh, array->data, array->capacity);
    c_init_mesh_array(array);
}

int c_push_mesh(CMeshArray *array, CMesh mesh)
{
    int index = 0;
    while (index < array->capacity) {
        if (array->data[index].vertex_array_object == 0) break;
        ++index;
    }

    if (index == array->capacity) {
        int old_capacity = array->capacity;
        array->capacity = GROW_ARRAY_CAPACITY(old_capacity);
        array->data = GROW_ARRAY(CMesh, array->data, old_capacity, array->capacity);

        for (int i = old_capacity; i < array->capacity; ++i) {
            c_zero_mesh(&array->data[i]);
        }
    }

    array->data[index] = mesh;
    return index;
}

void c_erase_mesh(CMeshArray *array, int index)
{
    c_free_mesh(&array->data[index]);
}