//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_FBO_MOD_H
#define MYENGINE_FBO_MOD_H

#include "general_include.h"

GENG_BEGIN

class FBOModule {
public:
    FBOModule();
    virtual ~FBOModule();

    virtual void createFBO() = 0;
    virtual void deleteFBO() = 0;
    virtual void bindFBO() = 0;
    virtual void unbindFBO() = 0;
protected:
    uint32_t width_;
    uint32_t height_;
};

GENG_END

#endif //MYENGINE_FBO_MOD_H
