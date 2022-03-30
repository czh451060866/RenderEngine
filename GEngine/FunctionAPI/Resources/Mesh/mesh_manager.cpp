//
// Created by zhanghong50 on 2022/1/20.
//

#include <Algorithms/Primitives/height_map_obj.h>
#include "mesh_manager.h"
#include "Algorithms/Primitives/primitives_include.h"
#include "RenderService/render_server.h"


GENG_BEGIN

MeshManager::MeshManager() {
}

MeshManager::~MeshManager() {

}

uint32_t MeshManager::getNumOfMeshes() {
        return meshes_.size();
}

void MeshManager::insertMesh(const MeshType & type) {
    if(meshes_.find(type) != meshes_.end()) {
        return;
    }

    std::shared_ptr<InstanceMesh> mesh;
    std::shared_ptr<BaseObject> obj;
    switch (type) {
        case PREDECLARED_PLANE:{
            obj = std::dynamic_pointer_cast<BaseObject>(std::make_shared<PlaneObject>());
            break;
        }
        case PREDECLARED_CUBE:{
            obj = std::dynamic_pointer_cast<BaseObject>(std::make_shared<CubeObject>());
            break;
        }
        case PREDECLARED_SPHERE:{
            obj = std::dynamic_pointer_cast<SphereObject>(std::make_shared<SphereObject>());
            break;
        }
        case HEIGHT_MAP:{
            obj = std::dynamic_pointer_cast<HeightMapObj>(std::make_shared<HeightMapObj>("/Users/chenzhihui/Software/opengl/AliceEngine/GEngine/ResourceFile/HeightMap/XriCX.png"));
            break;
        }
        default:
            break;
    }
    mesh = std::make_shared<InstanceMesh>(obj);
    meshes_[type] = mesh;
}
void MeshManager::deleteMesh() {

}

std::shared_ptr<InstanceMesh> MeshManager::accessMesh(const MeshType & type) {
    if(meshes_.find(type) != meshes_.end()){
        return meshes_.at(type);
    }
    return nullptr;
}

//void MeshManager::loadMesh(const std::shared_ptr<InstanceMesh> &mesh) {
//    RenderServer & render_server = RenderServer::getInstance();
//    render_server.l
//    mesh->is_loaded_ = true;
//}

GENG_END