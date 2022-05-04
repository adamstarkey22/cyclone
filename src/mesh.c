#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "mesh.h"

void c_mesh_init(c_mesh_t *mesh, int vertex_count, float *vertices, int element_count, unsigned *elements)
{
    mesh->element_count = element_count;

    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &mesh->vertex_buffer);
    glGenBuffers(1, &mesh->element_buffer);

    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(*vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_count * sizeof(*elements), elements, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(*vertices), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(*vertices), (void*)(3 * sizeof(*vertices)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(*vertices), (void*)(6 * sizeof(*vertices)));
}

void c_mesh_free(c_mesh_t *mesh)
{
    glDeleteVertexArrays(1, &mesh->VAO);
    glDeleteBuffers(1, &mesh->vertex_buffer);
    glDeleteBuffers(1, &mesh->element_buffer);

    mesh->VAO = 0;
    mesh->vertex_buffer = 0;
    mesh->element_buffer = 0;
    mesh->element_count = 0;
}

void c_mesh_draw(c_mesh_t *mesh)
{
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->element_count, GL_UNSIGNED_INT, (void*)0);
}