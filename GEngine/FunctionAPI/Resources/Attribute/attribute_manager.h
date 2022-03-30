//
// Created by HongZh on 2022/02/24, 20:24:50
//

#ifndef MYENGINE_ATTRIBUTE_MANAGER
#define MYENGINE_ATTRIBUTE_MANAGER

#include "Resources/resource_predeclare.h"
#include "AttributeSystem/object_attribute.h"

GENG_BEGIN


class AttributeManager{
public:
    AttributeManager();
    ~AttributeManager();

    void addObjectAttribute(const AttribInfo & attrib_info);
    std::shared_ptr<ObjectAttribute> queryObjectAttribute(const std::string & name);
private:
    std::map<std::string, std::shared_ptr<ObjectAttribute>> attributes_;
};

GENG_END

#endif //MYENGINE_ATTRIBUTE_MANAGER