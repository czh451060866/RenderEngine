//
// Created by HongZh on 2022/02/24, 20:30:55
//

#include "attribute_manager.h"
#include <cstddef>
#include <memory>

GENG_BEGIN

AttributeManager::AttributeManager(){

}

AttributeManager::~AttributeManager(){

}


void AttributeManager::addObjectAttribute(const AttribInfo & attrib_info){
    if(attributes_.find(attrib_info.name) == attributes_.end()){
        std::shared_ptr<ObjectAttribute> obj_attrib = std::make_shared<ObjectAttribute>();
        obj_attrib->addAttribute(attrib_info);
        attributes_[attrib_info.name] = obj_attrib;
    }
}

std::shared_ptr<ObjectAttribute> AttributeManager::queryObjectAttribute(const std::string &name){
    if(attributes_.find(name) != attributes_.end())
        return attributes_[name];
    return nullptr;
}

GENG_END