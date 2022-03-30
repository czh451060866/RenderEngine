//
// Created by zhanghong50 on 2022/2/11.
//

#ifndef MYENGINE_POINT_LIGHT_H
#define MYENGINE_POINT_LIGHT_H

#include "base_lighting.h"

GENG_BEGIN

class PointLight: public LightBase{
public:
    PointLight();
    ~PointLight();
};

GENG_END


#endif //MYENGINE_POINT_LIGHT_H
