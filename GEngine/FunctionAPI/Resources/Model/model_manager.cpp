//
// Created by HongZh on 2022/03/04, 17:59:46
//

#include "model_manager.h"
#include "FileSystem/file_handler_predeclared.h"

GENG_BEGIN

ModelManager::ModelManager(){

}

ModelManager::~ModelManager(){

}

void ModelManager::insertModel(const std::string & name, ModelInfo * model){
    std::shared_ptr<InstanceMesh> mesh = std::make_shared<InstanceMesh>();
    mesh->setVertices(model->vertices_);
    mesh->setDrawIndices(model->indices_);
    mesh->setMeshType(IMPORTED_MODEL);

    if(mesh->getNormals().empty()){
        NormalGenerator normal_generator;
        normal_generator.processNormalsSingleThread(mesh->getVertices(), mesh->getDrawIndices());
        mesh->setNormals(normal_generator.getNormals());
    }
    model_[name] = mesh;
}

std::shared_ptr<InstanceMesh> ModelManager::queryModel(const std::string & name){
    if(model_.find(name) != model_.end())
        return model_.at(name);
    return nullptr;
}


GENG_END