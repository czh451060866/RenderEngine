//
// Created by zhanghong50 on 2022/2/11.
//

#ifndef MYENGINE_BASE_LIGHTING_H
#define MYENGINE_BASE_LIGHTING_H

#include "AttributeSystem/attribute_base.h"

GENG_BEGIN

class LightBase: public AttributeBase{
public:
    LightBase();
    LightBase(LightType light_type);
    virtual ~LightBase();

    virtual void setColor(GVec3 color);
    virtual const GVec3 & getColor();
    virtual const LightType & getType();
protected:
    LightType light_type_ = NONE_LIGHT;
    GVec3 color_ = GVec3(1.0f);
};

GENG_END


#endif //MYENGINE_BASE_LIGHTING_H
