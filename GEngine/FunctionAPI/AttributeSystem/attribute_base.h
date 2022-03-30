//
// Created by HongZh on 2022/02/20, 17:59:14
//

#ifndef MYENGINE_ATTRIBUTE_BASE_H
#define MYENGINE_ATTRIBUTE_BASE_H

#include "attribute_predeclared.h"

GENG_BEGIN

class AttributeBase {
public:
    AttributeBase();
    AttributeBase(AttributeType type);
    virtual ~AttributeBase();
    const AttributeType & getAttributType();
protected:
    AttributeType attrib_type_ = NONE_ATTRIB;
};



GENG_END

#endif //MYENGINE_ATTRIBUTE_BASE_H