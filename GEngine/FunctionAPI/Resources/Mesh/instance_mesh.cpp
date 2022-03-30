//
// Created by zhanghong50 on 2022/1/19.
//

#include "instance_mesh.h"

GENG_BEGIN
InstanceMesh::InstanceMesh(): is_loaded_(false){

}

InstanceMesh::InstanceMesh(const std::shared_ptr<BaseObject> & obj) {
    setVertices(obj->getVertices());
    setNormals(obj->getNormals());
    setTangents(obj->getTangents());
    setBitanents(obj->getBitangents());
    setTexCoords(obj->getTexture());
    setDrawIndices(obj->getIndices());

    num_vertices_ = vertices_.size()/3;
    num_triangel_ = vert_indices_.size()/3;
    is_loaded_ = false;
    mesh_type_ = obj->getMeshType();
}

InstanceMesh::~InstanceMesh() {

}

uint32_t InstanceMesh::getNumOfSubMesh() {
    return meshes_.size();
}

void InstanceMesh::setVertices(const std::vector<float> &vertices) {
    vertices_.assign(vertices.begin(), vertices.end());  // TODO
    num_vertices_ = vertices.size()/3;
}

void InstanceMesh::setNormals(const std::vector<float> &normals) {
    normals_.assign(normals.begin(), normals.end()); // TODO
}

void InstanceMesh::setTangents(const std::vector<float> &tangents){
    tangents_.assign(tangents.begin(), tangents.end());
}

void InstanceMesh::setBitanents(const std::vector<float> &bitangents){
    bitangents_.assign(bitangents.begin(), bitangents.end());
}

void InstanceMesh::setTexCoords(const std::vector<float> &tex_coord) {
    tex_coord_.assign(tex_coord.begin(), tex_coord.end()); // TODO
}

void InstanceMesh::setDrawIndices(const std::vector<uint32_t> &indices) {
    vert_indices_.assign(indices.begin(), indices.end());
    num_triangel_ = vert_indices_.size()/3;
}

const std::vector<float> &InstanceMesh::getNormals() {
    return normals_;
}

const std::vector<float> & InstanceMesh::getTangents(){
    return tangents_;
}

const std::vector<float> & InstanceMesh::getBitangents(){
    return bitangents_;
}

const std::vector<float> & InstanceMesh::getVertices() {
    return vertices_;
}

const std::vector<float> &InstanceMesh::getTexCoords() {
    return tex_coord_;
}

const std::vector<uint32_t> & InstanceMesh::getDrawIndices() {
    return vert_indices_;
}

const uint32_t & InstanceMesh::getNumOfFace() {
    return num_triangel_;
}

const uint32_t & InstanceMesh::getNumOfVertices() {
    return num_vertices_;
}

const bool & InstanceMesh::isIntegrated() {
    return is_integrated_;
}

const MeshType & InstanceMesh::getMeshType() {
    return mesh_type_;
}


GENG_END