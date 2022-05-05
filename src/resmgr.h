#ifndef _CYCLONE_RESMGR_H_
#define _CYCLONE_RESMGR_H_

#include "mesh_array.h"

typedef struct {
    c_mesh_array_t meshes;
} c_resmgr_t;

void c_resmgr_init(c_resmgr_t *resmgr);
void c_resmgr_free(c_resmgr_t *resmgr);

void c_resmgr_push_mesh(c_resmgr_t * resmgr, c_mesh_t *mesh);

void c_resmgr_dbg(c_resmgr_t *resmgr);

#endif