#include <glad/gl.h>
#include <stdio.h>

#include "program.h"

static unsigned create_shader(unsigned type, const char *source, const char *type_str)
{
    unsigned shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetShaderInfoLog(shader, 512, NULL, info);
        fprintf(stderr, "Failed to compile shader of type %s: %s\n", type_str, info);
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

unsigned c_program_create(const char *vertex_shader_source, const char *fragment_shader_source)
{
    unsigned vertex_shader = create_shader(GL_VERTEX_SHADER, vertex_shader_source, "GL_VERTEX_SHADER");
    unsigned fragment_shader = create_shader(GL_FRAGMENT_SHADER, fragment_shader_source, "GL_FRAGMENT_SHADER");
    
    unsigned program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    
    glDetachShader(program, vertex_shader);
    glDeleteShader(vertex_shader);

    glDetachShader(program, fragment_shader);
    glDeleteShader(fragment_shader);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetProgramInfoLog(program, 512, NULL, info);
        fprintf(stderr, "Failed to link program: %s\n", info);
        glDeleteProgram(program);
        return 0;
    }

    return program;
}