//
// Created by zhanghong50 on 2022/1/20.
//

#include "light_node.h"

GENG_BEGIN

LightNode::LightNode() {
    // default
    light_label_ = POINT_LIGHT;
    node_type_ = LIGHT_NODE;
}

LightNode::LightNode(LightType light_t) {
    light_label_ = light_t;
    node_type_ = LIGHT_NODE;
}

LightNode::~LightNode() {

}

LightType LightNode::getLightLabel() {
    return light_label_;
}

void LightNode::setMesh(MeshType mesh_t) {
    mesh_type_ = mesh_t;
}




GENG_END