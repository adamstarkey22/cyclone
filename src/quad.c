#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "quad.h"

const float vertices[] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f
};

const unsigned indices[] = {
    0, 1, 2, 0, 2, 3
};

void c_quad_init(c_quad_t *quad)
{
    quad->count = 6;
    
    glGenVertexArrays(1, &quad->vao);
    glGenBuffers(1, &quad->vbo);
    glGenBuffers(1, &quad->ebo);

    glBindVertexArray(quad->vao);

    glBindBuffer(GL_ARRAY_BUFFER, quad->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

}

void c_quad_free(c_quad_t *quad)
{
    glDeleteVertexArrays(1, &quad->vao);
    glDeleteBuffers(1, &quad->vbo);
    glDeleteBuffers(1, &quad->ebo);

    quad->vao = 0;
    quad->vbo = 0;
    quad->ebo = 0;
    quad->count = 0;
}

void c_quad_draw(c_quad_t *quad)
{
    glBindVertexArray(quad->vao);
    glDrawElements(GL_TRIANGLES, quad->count, GL_UNSIGNED_INT, (void*)0);
}