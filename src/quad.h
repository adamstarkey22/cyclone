#ifndef _CYCLONE_QUAD_H_
#define _CYCLONE_QUAD_H_

typedef struct {
    unsigned vao;
    unsigned vbo;
    unsigned ebo;
    int count;
} c_quad_t;

void c_quad_init(c_quad_t *quad);
void c_quad_free(c_quad_t *quad);

void c_quad_draw(c_quad_t *quad);

#endif