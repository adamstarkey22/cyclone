#ifndef _CYCLONE_MESH_ARRAY_H_
#define _CYCLONE_MESH_ARRAY_H_

typedef struct _c_mesh_t {
    unsigned next;
    unsigned VAO;
    unsigned vertex_buffer;
    unsigned element_buffer;
    unsigned count;
} _c_mesh_t;

typedef struct _c_mesh_array_t {
    unsigned next;
    unsigned capacity;
    _c_mesh_t *data;
} _c_mesh_array_t;

void _c_mesh_array_init(_c_mesh_array_t *array);
void _c_mesh_array_free(_c_mesh_array_t *array);
unsigned _c_mesh_array_create_mesh(_c_mesh_array_t *array, int vertex_count, float *vertices, int element_count, unsigned *elements);
void _c_mesh_array_destroy_mesh(_c_mesh_array_t *array, unsigned id);
void _c_mesh_array_debug(_c_mesh_array_t *array);

#endif