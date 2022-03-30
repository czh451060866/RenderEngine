//
// Created by zhanghong50 on 2022/1/20.
//

#include "base_obj.h"

GENG_BEGIN
BaseObject::BaseObject():
is_generated_(false),
num_of_faces_(0),
num_of_vertices_(0) {
}

BaseObject::~BaseObject(){

}

void BaseObject::setVertices(std::vector<float> & vertices){
    vertices_.swap(vertices);
    num_of_vertices_ = vertices.size()/3.0;
}

void BaseObject::setNormals(std::vector<float> & normals){
    normals_.swap(normals);
}

void BaseObject::setTangents(std::vector<float> & tangents){
    tangents_.swap(tangents);
}

void BaseObject::setBitangents(std::vector<float> & bitangents){
    bitangents_.swap(bitangents);
}

void BaseObject::setTexCoords(std::vector<float> &tex_coords){
    tex_coords_.swap(tex_coords);
}

void BaseObject::setIndices(std::vector<uint32_t> &indices){
    vert_indices_.swap(indices);
    num_of_faces_ = indices.size()/3.0;
}

const uint32_t & BaseObject::getNumOfVertices(){
    return num_of_vertices_;
}

const uint32_t & BaseObject::getNumOfFaces(){
    return num_of_faces_;
}

const std::vector<float> & BaseObject::getVertices(){
    if(!is_generated_){
        generateMesh();
    }
    return vertices_;
}

const std::vector<float> & BaseObject::getTexture() {
    if(!is_generated_){
        generateMesh();
    }
    return tex_coords_;
}

const std::vector<float> & BaseObject::getNormals(){
    if(!is_generated_){
        generateMesh();
    }
    return normals_;
}

const std::vector<float> & BaseObject::getTangents(){
    if(!is_generated_){
        generateMesh();
    }
    return tangents_;
}

const std::vector<float> & BaseObject::getBitangents(){
    if(!is_generated_){
        generateMesh();
    }
    return bitangents_;
}

const std::vector<uint32_t> & BaseObject::getIndices() {
    if(!is_generated_){
        generateMesh();
    }
    return vert_indices_;
}

const MeshType & BaseObject::getMeshType() {
    return mesh_t_;
}

GENG_END