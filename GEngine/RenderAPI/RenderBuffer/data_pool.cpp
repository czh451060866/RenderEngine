//
// Created by zhanghong50 on 2022/2/1.
//

#include "data_pool.h"
#include "RenderFactory/render_factory.h"
#include "basic_include.h"

GENG_BEGIN

DataPool::DataPool() {
    activated_id_ = -1;
}

DataPool::~DataPool() {

}

DataPool &DataPool::getInstance() {
    static DataPool instance;
    return instance;
}

// TODO
std::vector<std::shared_ptr<DataModule>>
DataPool::loadData(std::shared_ptr<RenderMesh> mesh) {
    RenderFactory & render_factory = RenderFactory::getInstance();

    std::vector<std::shared_ptr<DataModule>> mesh_data;
    if(mesh->isIntegrated()){

    }else{

        // vertices
        const std::vector<float> & vertices = mesh->getVertices();
        std::shared_ptr<DataModule> vert_data = render_factory.assembleData(vertices);
        vert_data->setDataLayOut(VERTEX_POSITION);
        mesh_data.push_back(vert_data);

        // texture
        const std::vector<float> & tex_coords = mesh->getTexCoords();
        if(!tex_coords.empty()){
            std::shared_ptr<DataModule> tex_data = render_factory.assembleData(tex_coords);
            tex_data->setDataLayOut(TEXTURE_COORDINATE);
            mesh_data.push_back(tex_data);
        }

        // normals
        const std::vector<float> & normals = mesh->getNormals();
        if(!normals.empty()){
            std::shared_ptr<DataModule> norm_data = render_factory.assembleData(normals);
            norm_data->setDataLayOut(VERTEX_NORMAL);
            mesh_data.push_back(norm_data);
        }

        // tangents
        const std::vector<float> & tangents = mesh->getTangents();
        if(!tangents.empty()){
            std::shared_ptr<DataModule> tangent_data = render_factory.assembleData(tangents);
            tangent_data->setDataLayOut(VERTEX_TANGENT);
            mesh_data.push_back(tangent_data);
        }

        // bitangents
        const std::vector<float> & bitangents = mesh->getBitangents();
        if(!bitangents.empty()){
            std::shared_ptr<DataModule> bitangent_data = render_factory.assembleData(bitangents);
            bitangent_data->setDataLayOut(VERTEX_BITANGENT);
            mesh_data.push_back(bitangent_data);
        }

        // draw indices
        const std::vector<uint32_t> & draw_indices = mesh->getDrawIndices();
        std::shared_ptr<DataModule> indices_data = render_factory.assembleData(draw_indices);
        mesh_data.push_back(indices_data);
    }

    data_pool_.push_back(mesh_data);
    // TODO
    activated_id_ ++;
    return mesh_data;
}

GENG_END