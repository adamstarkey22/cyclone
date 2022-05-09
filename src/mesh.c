#include <glad/gl.h>

#include "internal.h"

void c_init_mesh(CMesh *mesh, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    mesh->element_count = element_count;

    glGenVertexArrays(1, &mesh->vertex_array_object);
    glGenBuffers(1, &mesh->vertex_buffer);
    glGenBuffers(1, &mesh->element_buffer);

    glBindVertexArray(mesh->vertex_array_object);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_count, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * element_count, elements, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, FALSE, sizeof(float) * 8, (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, FALSE, sizeof(float) * 8, (void *)(sizeof(float) * 3));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, FALSE, sizeof(float) * 8, (void *)(sizeof(float) * 6));
}

void c_free_mesh(CMesh *mesh)
{
    glDeleteVertexArrays(1, &mesh->vertex_array_object);
    glDeleteBuffers(1, &mesh->vertex_buffer);
    glDeleteBuffers(1, &mesh->element_buffer);
    c_zero_mesh(mesh);
}

void c_zero_mesh(CMesh *mesh)
{
    mesh->vertex_array_object = 0;
    mesh->vertex_buffer = 0;
    mesh->element_buffer = 0;
    mesh->element_count = 0;
}