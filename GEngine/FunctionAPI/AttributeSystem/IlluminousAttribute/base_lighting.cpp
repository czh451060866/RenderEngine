//
// Created by zhanghong50 on 2022/2/11.
//

#include "base_lighting.h"

GENG_BEGIN

LightBase::LightBase():
AttributeBase(ILLUMINOUS_ATTRIB) {
}

LightBase::LightBase(LightType light_type):
AttributeBase(ILLUMINOUS_ATTRIB),
light_type_(light_type){
}

LightBase::~LightBase() {

}


void LightBase::setColor(GVec3 color) {
    color_ = color;
}

const GVec3 & LightBase::getColor() {
    return color_;
}

const LightType & LightBase::getType() {
    return light_type_;
}


GENG_END