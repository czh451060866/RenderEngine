//
// Created by zhanghong50 on 2022/1/19.
//

#include "scene_node.h"

GENG_BEGIN
SceneNode::SceneNode() {
    node_name_ = "";
    node_type_ = SCENE_NODE;
    mesh_ = nullptr;
}

SceneNode::~SceneNode() {

}

void SceneNode::addChild(const std::shared_ptr<SceneNode> & node) {
    children_node_.push_back(node);
}

std::vector<std::shared_ptr<SceneNode>> & SceneNode::getChildrenNode() {
    return children_node_;
}

const NodeType & SceneNode::getNodeType() {
    return node_type_;
}





GENG_END