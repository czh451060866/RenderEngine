//
// Created by HongZh on 2022/02/20, 18:00:06
//

#include "attribute_base.h"

GENG_BEGIN

AttributeBase::AttributeBase(){

}
AttributeBase::AttributeBase(AttributeType type):
attrib_type_(type){

}

AttributeBase::~AttributeBase(){

}

const AttributeType & AttributeBase::getAttributType(){
    return attrib_type_;
}




GENG_END