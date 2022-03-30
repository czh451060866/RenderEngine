//
// Created by HongZh on 2022/03/12, 20:25:52
//

#ifndef MYENGINE_MESH_FROM_TEXTURE_H
#define MYENGINE_MESH_FROM_TEXTURE_H

#include "Algorithms/algo_predeclared.h"
#include "Algorithms/Primitives/base_obj.h"

GENG_BEGIN

/*
* generate vertices from texture
*/
class MeshGeneratorFromTex : public BaseObject {
private:
    float factor_;
public:
    MeshGeneratorFromTex();
    ~MeshGeneratorFromTex();
    void createMeshFromTexture(const uint32_t & width, const uint32_t & height, const uint32_t & channels, const char * buffer, bool need_normals = true);  // For example, generate mesh from a heightMap
    void modifyMeshByTexture(const uint32_t & width, const uint32_t & height, const uint32_t & channels, const char * buffer, bool need_normals = true);    // For example, modify mesh by a displacementMap
};

GENG_END

#endif //MYENGINE_MESH_FROM_TEXTURE_H