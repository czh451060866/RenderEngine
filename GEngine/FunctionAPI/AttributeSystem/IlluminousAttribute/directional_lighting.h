//
// Created by zhanghong50 on 2022/2/11.
//

#ifndef MYENGINE_DIRECTIONAL_LIGHTING_H
#define MYENGINE_DIRECTIONAL_LIGHTING_H

#include "base_lighting.h"

GENG_BEGIN

class DirectionalLight: public LightBase{
public:
    DirectionalLight();
    ~DirectionalLight();
};

GENG_END


#endif //MYENGINE_DIRECTIONAL_LIGHTING_H
