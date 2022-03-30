//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_MODEL_NODE_H
#define MYENGINE_MODEL_NODE_H

#include "scene_node.h"

GENG_BEGIN
class ModelNode: public SceneNode {
private:
    ModelType model_type_;
public:
    ModelNode();
    ~ModelNode();
};
GENG_END

#endif //MYENGINE_MODEL_NODE_H
