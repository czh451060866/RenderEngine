//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_DRAW_MOD_H
#define MYENGINE_DRAW_MOD_H

#include "general_include.h"

GENG_BEGIN

class DrawModule {
protected:
    DrawModule();
public:
    virtual ~DrawModule();
    static std::shared_ptr<DrawModule> getInstance(uint32_t n_triangle);

    virtual void drawElement() = 0;
    virtual void drawArrays() = 0;

};

GENG_END


#endif //MYENGINE_DRAW_MOD_H
