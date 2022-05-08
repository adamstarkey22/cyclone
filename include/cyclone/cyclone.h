#ifndef _CYCLONE_H_
#define _CYCLONE_H_

#define CYCLONE_TRUE  1
#define CYCLONE_FALSE 0

typedef int c_bool_t;

typedef struct c_instance_t c_instance_t;

c_bool_t c_init();
void c_free();

c_instance_t *c_create_instance();
void c_destroy_instance(c_instance_t *instance);

unsigned c_create_mesh(c_instance_t *instance, int vertex_count, float *vertices, int element_count, unsigned *elements);
unsigned c_create_program(c_instance_t *instance, const char *vertex_shader_source, const char *fragment_shader_source);
unsigned c_create_texture(c_instance_t *instance);

void c_destroy_program(c_instance_t *instance, unsigned id);

#endif