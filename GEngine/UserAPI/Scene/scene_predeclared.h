//
// Created by zhanghong50 on 2022/2/18.
//

#ifndef MYENGINE_SCENE_PREDECLARED_H
#define MYENGINE_SCENE_PREDECLARED_H

#include "general_include.h"
#include "engine_math.h"


GENG_BEGIN

enum NodeType {
    SCENE_NODE = 0,
    CAMERA_NODE,
    LIGHT_NODE,
    MODEL_NODE,
    PRIMITIVE_NODE
};

GENG_END

#endif //MYENGINE_SCENE_PREDECLARED_H
