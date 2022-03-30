//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_MESH_MANAGER_H
#define MYENGINE_MESH_MANAGER_H

#include "instance_mesh.h"

GENG_BEGIN

class MeshManager {
private:
    std::map<MeshType, std::shared_ptr<InstanceMesh>> meshes_;
public:
    MeshManager();
    ~MeshManager();

    uint32_t getNumOfMeshes();

    void insertMesh(const MeshType & type);
    void deleteMesh();
    std::shared_ptr<InstanceMesh> accessMesh(const MeshType & type);

//    void loadMesh(const std::shared_ptr<InstanceMesh> & mesh);

};

GENG_END

#endif //MYENGINE_MESH_MANAGER_H
