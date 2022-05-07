#include <cyclone/cyclone.h>
#include <stdio.h>

static void error_callback(int error_code, const char *description)
{
    fprintf(stderr, "GLFW error: %s\n", description);
}

c_bool_t c_init()
{
    if (!glfwInit()) return CYCLONE_FALSE;
    return CYCLONE_TRUE;
}

void c_free()
{
    glfwTerminate();
}