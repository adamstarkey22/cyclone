#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "resmgr.h"

void c_resmgr_init(c_resmgr_t *resmgr)
{
    c_mesh_array_init(&resmgr->meshes);
}

void c_resmgr_free(c_resmgr_t *resmgr)
{
    c_mesh_array_free(&resmgr->meshes);
}

void c_resmgr_push_mesh(c_resmgr_t * resmgr, c_mesh_t *mesh)
{
    c_mesh_array_push(&resmgr->meshes, mesh);
}

void c_resmgr_dbg(c_resmgr_t *resmgr)
{
    for (int i = 0; i < resmgr->meshes.count; ++i) {
        c_mesh_t mesh = resmgr->meshes.data[i];
        printf("[%d] %d %d %d %d\n", i, mesh.VAO, mesh.vertex_buffer, mesh.element_buffer, mesh.element_count);
    }
}