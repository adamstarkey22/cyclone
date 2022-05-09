#include <cyclone/cyclone.h>
#include <stdio.h>

static void error_callback(int error_code, const char *description)
{
    fprintf(stderr, "GLFW error: %s\n", description);
}

CBool c_init()
{
    if (!glfwInit()) return FALSE;
    return TRUE;
}

void c_free()
{
    glfwTerminate();
}