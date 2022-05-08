#include <glad/gl.h>
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "program_array.h"

void _c_init_program_array(_c_program_array_t *array)
{
    array->capacity = 0;
    array->data = NULL;
}

void _c_free_program_array(_c_program_array_t *array)
{
    FREE_ARRAY(unsigned, array->data, array->capacity);
    _c_init_program_array(array);
}

static unsigned create_shader(unsigned type, const char *type_str, const char *source)
{
    unsigned shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        fprintf(stderr, "Failed to compile shader of type %s: %s\n", type_str, info_log);
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

static unsigned create_program(const char *vertex_shader_source, const char *fragment_shader_source)
{
    unsigned vertex_shader = create_shader(GL_VERTEX_SHADER, "GL_VERTEX_SHADER", vertex_shader_source);
    unsigned fragment_shader = create_shader(GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER", fragment_shader_source);
    unsigned program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    glDetachShader(program, vertex_shader);
    glDetachShader(program, fragment_shader);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetProgramInfoLog(program, 512, NULL, info_log);
        fprintf(stderr, "Failed to link shader program: %s\n", info_log);
        glDeleteProgram(program);
        return 0;
    }

    return program;
}

unsigned _c_create_program(_c_program_array_t *array, const char *vertex_shader_source, const char *fragment_shader_source)
{
    unsigned index = 0;
    while (index < array->capacity) {
        if (array->data[index] == 0) break;
        ++index;
    }

    if (index == array->capacity) {
        unsigned old_capacity = array->capacity;
        array->capacity = GROW_ARRAY_CAPACITY(old_capacity);
        array->data = GROW_ARRAY(unsigned, array->data, old_capacity, array->capacity);

        for (unsigned i = old_capacity; i < array->capacity; ++i) {
            array->data[i] = 0;
        }
    }

    unsigned program = create_program(vertex_shader_source, fragment_shader_source);
    if (program == 0) return 0;
    array->data[index] = program;
    return index + 1;
}

void _c_destroy_program(_c_program_array_t *array, unsigned id)
{
    if (id == 0) return;
    unsigned index = id - 1;

    glDeleteProgram(array->data[index]);
    array->data[index] = 0;
}