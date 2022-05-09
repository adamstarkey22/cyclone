#ifndef CYCLONE_H
#define CYCLONE_H

#define TRUE  1
#define FALSE 0

typedef int CBool;
typedef struct CInstance CInstance;

CBool c_init();
void c_free();

CInstance *c_create_instance();
void c_destroy_instance();

int c_create_mesh(CInstance *instance, int vertex_count, float *vertices, int element_count, unsigned *elements);
int c_create_program(CInstance *instance, const char *vertex_shader_source, const char *fragment_shader_source);

#endif