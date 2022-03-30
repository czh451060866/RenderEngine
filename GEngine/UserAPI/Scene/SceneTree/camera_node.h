//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_CAMERA_NODE_H
#define MYENGINE_CAMERA_NODE_H

#include "scene_node.h"

GENG_BEGIN

class CameraNode: public SceneNode{
private:
    CameraType camera_label_;
public:
    CameraNode();
    CameraNode(CameraType type);
    ~CameraNode();

    // virtual
    // functions
    CameraType getCameraLabel();

};

GENG_END


#endif //MYENGINE_CAMERA_NODE_H
