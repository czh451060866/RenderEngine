//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_INSTANCE_MESH_H
#define MYENGINE_INSTANCE_MESH_H

#include "Resources/resource_predeclare.h"
#include "Algorithms/Primitives/base_obj.h"
#include "RenderData/render_mesh.h"

GENG_BEGIN

class InstanceMesh: public RenderMesh {
private:
    std::vector<std::shared_ptr<InstanceMesh>> meshes_;
    std::vector<float> vertices_;
    std::vector<float> tex_coord_;
    std::vector<float> normals_;
    std::vector<float> tangents_;
    std::vector<float> bitangents_;
    std::vector<uint32_t> vert_indices_;

    uint32_t num_triangel_;
    uint32_t num_vertices_;

public:
    bool is_loaded_;
    
    explicit InstanceMesh();
    explicit InstanceMesh(const std::shared_ptr<BaseObject> & obj);
    ~InstanceMesh();

    uint32_t getNumOfSubMesh();

    void setVertices(const std::vector<float> & vertices);
    void setTexCoords(const std::vector<float> & tex_coord);
    void setNormals(const std::vector<float> & normals);
    void setTangents(const std::vector<float> & tangents);
    void setBitanents(const std::vector<float> & bitangents);
    void setDrawIndices(const std::vector<uint32_t> & indices);

    const std::vector<float> & getVertices() override;
    const std::vector<float> & getTexCoords() override;
    const std::vector<float> & getNormals() override;
    const std::vector<float> & getTangents() override;
    const std::vector<float> & getBitangents() override;
    const std::vector<uint32_t> & getDrawIndices() override;
    const uint32_t & getNumOfFace() override;
    const uint32_t & getNumOfVertices() override;
    const MeshType & getMeshType() override;
    const bool & isIntegrated() override;

};

GENG_END

#endif //MYENGINE_INSTANCE_MESH_H
