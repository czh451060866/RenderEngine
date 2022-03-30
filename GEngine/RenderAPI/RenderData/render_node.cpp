//
// Created by zhanghong50 on 2022/1/24.
//

#include "render_node.h"

GENG_BEGIN
RenderNode::RenderNode() {

}

RenderNode::~RenderNode() {

}

bool RenderNode::operator== (const RenderNode & node){
    if( this->effect_name_ == node.effect_name_ &&
        this->render_queue_ == node.render_queue_){
            return true;
        }
    return false;
}

// void RenderNode::setMeshPtr(std::shared_ptr<RenderMesh> mesh) {
//     mesh_ = mesh;
//     mesh_type_ = mesh->getMeshType();
// }

// std::shared_ptr<RenderMesh> RenderNode::getMesh() {
//     return mesh_;
// }

const RenderType & RenderNode::getRenderType(){
    return render_type_;
}

const QueueType & RenderNode::getQueueType(){
    return render_queue_;
}

const MeshType & RenderNode::getMeshType(){
    return mesh_type_;
}

const std::string & RenderNode::getEffectName(){
    return effect_name_;
}

const std::string & RenderNode::getLightingName(){
    return lighting_name_;
}

const std::string & RenderNode::getCameraName(){
    return camera_name_;
}

const std::string & RenderNode::getNodeName(){
    return node_name_;
}

void RenderNode::setEffect(const std::string &name){
    effect_name_ = name;
}
void RenderNode::setLighting(const std::string &name){
    lighting_name_ = name;
}
void RenderNode::setCamera(const std::string &name){
    camera_name_ = name;
}
void RenderNode::setNodeName(const std::string &name){
    node_name_ = name;
}
GENG_END
