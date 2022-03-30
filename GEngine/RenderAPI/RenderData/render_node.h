//
// Created by zhanghong50 on 2022/1/24.
//

#ifndef MYENGINE_RENDER_NODE_H
#define MYENGINE_RENDER_NODE_H

#include "data_predeclared.h"
#include "RenderAPI/RenderQueue/render_predeclared.h"
#include "render_mesh.h"
#include <string>


GENG_BEGIN
class RenderNode {
public:
    RenderNode();
    virtual ~RenderNode();
    bool operator== (const RenderNode & node); 

    const RenderType & getRenderType();
    const QueueType & getQueueType();
    const MeshType & getMeshType();

    const std::string & getEffectName();
    const std::string & getLightingName(); // query light name and camera name
    const std::string & getCameraName();
    const std::string & getNodeName();

    void setEffect(const std::string & name);
    void setCamera(const std::string & name);
    void setLighting(const std::string & name);
    void setNodeName(const std::string & name);
    // void setMeshPtr(std::shared_ptr<RenderMesh> mesh);
    // std::shared_ptr<RenderMesh> getMesh();

protected:

    RenderType render_type_ = OPAQUE;   // render info
    QueueType render_queue_ = OPAQUE_QUEUE;
    MeshType mesh_type_ = NONE_MESH;// type of mesh

    std::string effect_name_;// type of effect
    std::string lighting_name_;
    std::string camera_name_;
    std::string node_name_;
    std::shared_ptr<RenderMesh> mesh_;

};
GENG_END

#endif //MYENGINE_RENDER_NODE_H
