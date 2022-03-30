//
// Created by zhanghong50 on 2022/1/25.
//

#ifndef MYENGINE_FBO_POOL_H
#define MYENGINE_FBO_POOL_H



#include "buffer_predeclared.h"
#include "RenderModules/fbo_mod.h"

GENG_BEGIN

class FBOPool {
public:
    ~FBOPool();
    static FBOPool & getInstance();
    FBOPool(const FBOPool&)=delete;
    FBOPool& operator=(const FBOPool&)=delete;

    uint32_t createFBO(uint32_t w, uint32_t h);
    void deleteFBO(uint32_t f_id);
protected:
    std::array<std::shared_ptr<FBOModule>, MAX_NUM_FBO> fbo_pool_;
    uint32_t free_id;
private:
    FBOPool();
};

GENG_END

#endif //MYENGINE_FBO_POOL_H
