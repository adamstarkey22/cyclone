#include <glad/gl.h>
#include <stdio.h>

#include "internal.h"

static unsigned create_shader(unsigned type, const char *type_str, const char *source)
{
    unsigned shader = glCreateShader(type);
    if (shader) {
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success) {
            return shader;
        } else {
            char info_log[512];
            glGetShaderInfoLog(shader, 512, NULL, info_log);
            fprintf(stderr, "Failed to compile shader of type %s: %s\n", type_str, info_log);
        }
        glDeleteShader(shader);
    }
    return 0;
}

void c_init_program(CProgram *program, const char *vertex_shader_source, const char *fragment_shader_source)
{
    unsigned vertex_shader = create_shader(GL_VERTEX_SHADER, "GL_VERTEX_SHADER", vertex_shader_source);
    if (vertex_shader) {
        unsigned fragment_shader = create_shader(GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER", fragment_shader_source);
        if (fragment_shader) {
            unsigned tmp_program = glCreateProgram();
            if (tmp_program) {
                glAttachShader(tmp_program, vertex_shader);
                glAttachShader(tmp_program, fragment_shader);
                
                glLinkProgram(tmp_program);
                
                glDetachShader(tmp_program, vertex_shader);
                glDetachShader(tmp_program, fragment_shader);

                int success;
                glGetProgramiv(tmp_program, GL_LINK_STATUS, &success);
                if (success) {
                    glDeleteShader(vertex_shader);
                    glDeleteShader(fragment_shader);
                    *program = tmp_program;
                    return;
                } else {
                    char info_log[512];
                    glGetProgramInfoLog(tmp_program, 512, NULL, info_log);
                    fprintf(stderr, "Failed to link program: %s\n", info_log);
                }
                glDeleteProgram(tmp_program);
            }
            glDeleteShader(fragment_shader);
        }
        glDeleteShader(vertex_shader);
    }
    *program = 0;
}

void c_free_program(CProgram *program)
{
    glDeleteProgram(*program);
    c_zero_program(program);
}

void c_zero_program(CProgram *program)
{
    *program = 0;
}