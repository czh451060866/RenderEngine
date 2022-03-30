//
// Created by zhanghong50 on 2022/1/19.
//

#include "data_mod.h"
#include "data_buffer.h"
GENG_BEGIN

DataModule::DataModule() {
}

DataModule::~DataModule() {

}

std::shared_ptr<DataModule> DataModule::getInstancePtr() {
    std::shared_ptr<DataModule> data = std::make_shared<DataBuffer>();
    return data;
}

const AttributeKey & DataModule::getDataLayOut(){
    return attrib_key_;
}

void DataModule::setDataLayOut(AttributeKey key){
    attrib_key_ = key;
}

GENG_END