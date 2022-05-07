#include <glad/gl.h>
#include <stdio.h>
#include <stdlib.h>

#include "mesh_array.h"
#include "memory.h"

void _c_mesh_array_init(_c_mesh_array_t *array)
{
    array->next = 0;
    array->capacity = 0;
    array->data = NULL;
}

void _c_mesh_array_free(_c_mesh_array_t *array)
{
    FREE_ARRAY(_c_mesh_t, array->data, array->capacity);
    _c_mesh_array_init(array);
}

static void init_mesh(_c_mesh_t *mesh, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    mesh->count = element_count;
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &mesh->vertex_buffer);
    glGenBuffers(1, &mesh->element_buffer);

    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_count * sizeof(unsigned), elements, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
}

unsigned _c_mesh_array_create_mesh(_c_mesh_array_t *array, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    if (array->next == array->capacity) { // if the array is filled, resize it
        unsigned old_capacity = array->capacity;
        array->capacity = GROW_ARRAY_CAPACITY(old_capacity);
        array->data = GROW_ARRAY(_c_mesh_t, array->data, old_capacity, array->capacity);
        // the new free elements should point to each other to continue the chain
        for (unsigned i = old_capacity; i < array->capacity; ++i) {
            array->data[i].next = i + 1;
        }
    }

    unsigned insertion_index = array->next;
    array->next = array->data[insertion_index].next;
    init_mesh(&array->data[insertion_index], vertex_count, vertices, element_count, elements);
    return insertion_index + 1;
}

static void free_mesh(_c_mesh_t *mesh)
{
    mesh->count = 0;
    glDeleteVertexArrays(1, &mesh->VAO);
    glDeleteBuffers(1, &mesh->vertex_buffer);
    glDeleteBuffers(1, &mesh->element_buffer);
}

void _c_mesh_array_destroy_mesh(_c_mesh_array_t *array, unsigned id)
{
    if (id == 0) return;
    unsigned index = id - 1;
    free_mesh(&array->data[index]);
    
    unsigned last = array->next;

    if (last > index) { // insert to front of chain
        array->next = index;
        array->data[index].next = last;
        return;
    }
    
    unsigned next = array->data[last].next;
    while (next < index) {
        last = next;
        next = array->data[last].next;
    }

    array->data[last].next = index;
    array->data[index].next = next;
}

void _c_mesh_array_debug(_c_mesh_array_t *array)
{
    printf("capacity: %d\n", array->capacity);
    printf("chain: ");
    int index = array->next;
    while (index < array->capacity) {
        printf(" -> %d", index);
        index = array->data[index].next;
    }
    printf("\n");
}