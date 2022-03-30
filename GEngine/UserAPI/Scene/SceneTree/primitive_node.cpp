//
// Created by zhanghong50 on 2022/1/20.
//

#include "primitive_node.h"

GENG_BEGIN

PrimitiveNode::PrimitiveNode(MeshType mesh_type) {
    mesh_type_ = mesh_type;
    node_type_ = PRIMITIVE_NODE;
}

PrimitiveNode::~PrimitiveNode() {

}



GENG_END