#include <glad/gl.h>

#include "draw.h"
#include "init.h"
#include "instance.h"

int main()
{
    c_init_lib();

    c_instance_t c;
    c_init(&c);
    
    while (!c_shouldclose(&c)) {
        c_start(&c);
        c_draw_image(&c);
        c_end(&c);
    }

    c_free(&c);
    c_free_lib();
    return 0;
}