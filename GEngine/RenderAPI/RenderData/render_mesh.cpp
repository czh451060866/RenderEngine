//
// Created by zhanghong50 on 2022/2/1.
//

#include "render_mesh.h"

GENG_BEGIN
RenderMesh::RenderMesh() {

}

RenderMesh::~RenderMesh() {

}

void RenderMesh::setMeshType(const MeshType & type){
    mesh_type_ = type;
}


GENG_END