//
// Created by zhanghong50 on 2022/2/1.
//

#ifndef MYENGINE_RENDER_MESH_H
#define MYENGINE_RENDER_MESH_H
#include "data_predeclared.h"


GENG_BEGIN

class RenderMesh {
public:
    RenderMesh();
    virtual ~RenderMesh();

    virtual void setMeshType(const MeshType & type);
    virtual const bool & isIntegrated() = 0;
    virtual const std::vector<float> & getVertices() = 0;
    virtual const std::vector<float> & getTexCoords() = 0;
    virtual const std::vector<float> & getNormals() = 0;
    virtual const std::vector<float> & getTangents() = 0;
    virtual const std::vector<float> & getBitangents() = 0;
    virtual const std::vector<uint32_t> & getDrawIndices() = 0;
    virtual const uint32_t & getNumOfFace() = 0;
    virtual const uint32_t & getNumOfVertices() = 0;
    virtual const MeshType & getMeshType() = 0;
protected:
    bool is_integrated_ = false;
    MeshType mesh_type_ = NONE_MESH;
};

GENG_END


#endif //MYENGINE_RENDER_MESH_H
