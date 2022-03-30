//
// Created by zhanghong50 on 2022/1/20.
//

#include "plane_obj.h"
#include "Algorithms/MeshProcessor/normal_generator.h"

GENG_BEGIN

PlaneObject::PlaneObject() {

}

PlaneObject::~PlaneObject() {

}

void PlaneObject::generateMesh() {
    vertices_  = {
            0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
            -0.5f,-0.5f, 0.0f,
            0.5f,-0.5f, 0.0f // v0,v1,v2,v3
    };

    normals_ = {
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f
    };

    tex_coords_ = {
            // u, v, w, default(-1.0)
            1.0f, 1.0f, -1.0f, 
            0.0f, 1.0, -1.0f,
            0.0f, 0.0f, -1.0f,
            1.0f, 0.0f, -1.0f
    };


    vert_indices_ = {
            0, 1, 2,
            2, 3, 0
    };

    NormalGenerator normal_generator;
    normal_generator.processTangentsSingleThread(vertices_, vert_indices_, tex_coords_);
    setTangents(normal_generator.getTangents());
    setBitangents(normal_generator.getBitangents());

    is_generated_ = true;
    mesh_t_ = PREDECLARED_PLANE;
}


GENG_END