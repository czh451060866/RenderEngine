//
// Created by zhanghong50 on 2022/1/25.
//

#include "fbo_pool.h"
#include "frame_buffer.h"

GENG_BEGIN
FBOPool::FBOPool() {
    free_id = 0;
    fbo_pool_ = {nullptr};
}

FBOPool::~FBOPool() {

}

FBOPool & FBOPool::getInstance() {
    static FBOPool fbo_pool_;
    return fbo_pool_;
}

uint32_t FBOPool::createFBO(uint32_t w, uint32_t h) {
    if(free_id < MAX_NUM_FBO){
        fbo_pool_[free_id] = std::dynamic_pointer_cast<FBOModule>(std::make_shared<FrameBuffer>(w,h));
    }
    return free_id++;
}

void FBOPool::deleteFBO(uint32_t f_id) {
    free_id = f_id;
}


GENG_END