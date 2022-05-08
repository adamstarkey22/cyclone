#ifndef _CYCLONE_PROGRAM_ARRAY_H_
#define _CYCLONE_PROGRAM_ARRAY_H_

typedef struct {
    unsigned capacity;
    unsigned *data;
} _c_program_array_t;

void _c_init_program_array(_c_program_array_t *array);
void _c_free_program_array(_c_program_array_t *array);
unsigned _c_create_program(_c_program_array_t *array, const char *vertex_shader_source, const char *fragment_shader_source);
void _c_destroy_program(_c_program_array_t *array, unsigned id);

#endif