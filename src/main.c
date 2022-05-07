#include <cyclone/cyclone.h>
#include <stdio.h>

#include "mesh_array.h"

float vertices[] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
};

unsigned elements[] = { 0, 1, 2, 0, 2, 3 };

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

    c_destroy_instance(c);
    c_free();
    return 0;
}