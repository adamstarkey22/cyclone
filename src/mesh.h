#ifndef _CYCLONE_MESH_H_
#define _CYCLONE_MESH_H_

typedef struct {
    unsigned VAO;
    unsigned vertex_buffer;
    unsigned element_buffer;
    int element_count;
} c_mesh_t;

void c_mesh_init(c_mesh_t *mesh, int vertex_count, const float *vertices, int element_count, const unsigned *elements);
void c_mesh_free(c_mesh_t *mesh);
void c_mesh_draw(c_mesh_t *mesh);

#endif