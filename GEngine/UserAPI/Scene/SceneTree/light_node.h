//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_LIGHT_NODE_H
#define MYENGINE_LIGHT_NODE_H

#include "scene_node.h"

GENG_BEGIN

class LightNode: public SceneNode{
private:
    LightType light_label_;

public:
    LightNode();
    LightNode(LightType light_t);
    ~LightNode();

    // functions
    LightType getLightLabel();      // get light label
    void setMesh(MeshType mesh_t);    // set the shape
};

GENG_END

#endif //MYENGINE_LIGHT_NODE_H
