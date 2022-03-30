//
// Created by zhanghong50 on 2022/1/19.
//

#include "draw_mod.h"
#include "draw_call.h"

GENG_BEGIN

DrawModule::DrawModule() {

}

DrawModule::~DrawModule() {

}

std::shared_ptr<DrawModule> DrawModule::getInstance(uint32_t n_triangle) {
    std::shared_ptr<DrawModule> instance_ptr = std::make_shared<DrawCall>(n_triangle);
    return instance_ptr;
}


GENG_END