#include <glad/gl.h>

#include "draw.h"


void c_start(c_instance_t *c)
{
    int width, height;
    glfwGetFramebufferSize(c->window, &width, &height);
    glViewport(0, 0, width, height);
    
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void c_end(c_instance_t *c)
{
    glfwSwapBuffers(c->window);
    glfwPollEvents();
}

void c_draw_image(c_instance_t *c)
{
    c_quad_draw(&c->quad);
}