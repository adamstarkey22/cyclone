#include "instance.h"

int main()
{
    c_init_libs();

    c_instance_t c;
    c_init(&c);

    while (!glfwWindowShouldClose(c.window)) {
        c_start(&c);
        c_end(&c);
    }

    c_free(&c);
    c_free_libs();
    return 0;
}