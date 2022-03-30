//
// Created by HongZh on 2022/03/04, 17:51:51
//

#ifndef MYENGINE_MODEL_MANAGER_H
#define MYENGINE_MODEL_MANAGER_H

#include "FileSystem/file_handler_predeclared.h"
#include "Resources/resource_predeclare.h"
#include "Resources/Mesh/instance_mesh.h"
#include "Algorithms/MeshProcessor/normal_generator.h"

GENG_BEGIN

class ModelManager{
public:
    ModelManager();
    ~ModelManager();

    void insertModel(const std::string & name, ModelInfo * model);
    std::shared_ptr<InstanceMesh> queryModel(const std::string & name);
private:
    std::map<std::string, std::shared_ptr<InstanceMesh>> model_;
};

GENG_END

#endif //MYENGINE_MODEL_MANAGER_H