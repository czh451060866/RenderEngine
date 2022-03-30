//
// Created by zhanghong50 on 2022/1/20.
//

#include "model_node.h"
#include "Scene/scene_predeclared.h"
#include "general_include.h"

GENG_BEGIN

ModelNode::ModelNode(){
    mesh_type_ = IMPORTED_MODEL;
    node_type_ = MODEL_NODE;
}

ModelNode::~ModelNode(){

}

GENG_END