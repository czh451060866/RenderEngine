//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_PRIMITIVE_NODE_H
#define MYENGINE_PRIMITIVE_NODE_H

#include "scene_node.h"

GENG_BEGIN

class PrimitiveNode: public SceneNode{
private:
public:
    explicit PrimitiveNode(MeshType mesh_type);
    ~PrimitiveNode();

    // virtual
    // functions
};

GENG_END

#endif //MYENGINE_PRIMITIVE_NODE_H
