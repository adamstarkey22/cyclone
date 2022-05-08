#include <cyclone/cyclone.h>
#include <glad/gl.h>
#include <stdio.h>

#include "instance.h"
#include "mesh_array.h"

float vertices[] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
};

unsigned elements[] = { 0, 1, 2, 0, 2, 3 };

const char *vertex_shader_source =
"#version 400\n"
"layout (location=0) in vec3 a_position;\n"
"layout (location=1) in vec3 a_normal;\n"
"layout (location=2) in vec2 a_texcoord;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(a_position, 1.0);\n"
"}";

const char *fragment_shader_source =
"#version 400\n"
"out vec4 f_color;\n"
"void main()\n"
"{\n"
"    f_color = vec4(1.0, 0.5, 0.25, 1.0);\n"
"}";

int main()
{
    if (!c_init()) {
        fprintf(stderr, "Failed to initialise cyclone\n");
        return 1;
    }

    c_instance_t *c = c_create_instance();
    if (c == NULL) {
        fprintf(stderr, "Failed to create cyclone instance\n");
    }

    unsigned quad = c_create_mesh(c, 32, vertices, 6, elements);
    unsigned program = c_create_program(c, vertex_shader_source, fragment_shader_source);

    while (!glfwWindowShouldClose(c->window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(c->programs.data[program - 1]);
        glBindVertexArray(c->meshes.data[quad - 1].VAO);
        glDrawElements(GL_TRIANGLES, c->meshes.data[quad - 1].count, GL_UNSIGNED_INT, (void *)0);
        glfwSwapBuffers(c->window);
        glfwPollEvents();
    }

    c_destroy_instance(c);
    c_free();
    return 0;
}