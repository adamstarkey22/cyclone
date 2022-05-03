#include "instance.h"

void c_init_libs()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void c_free_libs()
{
    glfwTerminate();
}

void c_init(c_instance_t *c)
{
    c->window = glfwCreateWindow(640, 480, "cyclone", NULL, NULL);
    glfwMakeContextCurrent(c->window);
}

void c_free(c_instance_t *c)
{
    glfwDestroyWindow(c->window);
}

void c_start(c_instance_t *c)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void c_end(c_instance_t *c)
{
    glfwSwapBuffers(c->window);
    glfwPollEvents();
}