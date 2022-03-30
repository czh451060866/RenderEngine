//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_BASE_OBJ_H
#define MYENGINE_BASE_OBJ_H

#include "primitives_predeclared.h"

GENG_BEGIN

class BaseObject {
protected:
    std::vector<float> vertices_;
    std::vector<float> tex_coords_;
    std::vector<float> normals_;
    std::vector<float> tangents_;
    std::vector<float> bitangents_;
    std::vector<uint32_t> vert_indices_;

    uint32_t num_of_vertices_;
    uint32_t num_of_faces_;
    MeshType mesh_t_;

    bool is_generated_; // 避免重复计算
    virtual void generateMesh() {};
public:
    BaseObject();
    ~BaseObject();

    void setVertices(std::vector<float> & vertices);
    void setNormals(std::vector<float> & normals);
    void setTangents(std::vector<float> & tangents);
    void setBitangents(std::vector<float> & bitangents);
    void setIndices(std::vector<uint32_t> & indices);
    void setTexCoords(std::vector<float> & tex_coords);


    virtual const uint32_t & getNumOfVertices();
    virtual const uint32_t & getNumOfFaces();
    virtual const std::vector<float> & getVertices();
    virtual const std::vector<float> & getTexture();
    virtual const std::vector<float> & getNormals();
    virtual const std::vector<float> & getTangents();
    virtual const std::vector<float> & getBitangents();
    virtual const std::vector<uint32_t> & getIndices();
    virtual const MeshType & getMeshType();
};

GENG_END

#endif //MYENGINE_BASE_OBJ_H
