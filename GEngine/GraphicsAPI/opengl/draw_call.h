//
// Created by zhanghong50 on 2022/1/26.
//

#ifndef MYENGINE_DRAW_CALL_H
#define MYENGINE_DRAW_CALL_H

#include "graphic_predeclared.h"
#include "RenderModules/draw_mod.h"

GENG_BEGIN

class DrawCall: public DrawModule {
public:
    DrawCall();
    DrawCall(uint32_t n_triangle);
    ~DrawCall();

    virtual void drawElement() override;
    virtual void drawArrays() override;
public: //TODO
    std::string type_;
    uint32_t num_triangle_;
};

GENG_END


#endif //MYENGINE_DRAW_CALL_H
