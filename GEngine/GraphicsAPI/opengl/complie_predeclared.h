//
// Created by zhanghong50 on 2022/1/28.
//

#ifndef MYENGINE_COMPLIE_PREDECLARED_H
#define MYENGINE_COMPLIE_PREDECLARED_H

#include "graphic_predeclared.h"
#include "RenderModules/initialization_mod.h"

GENG_BEGIN
class InitGraphic: public InitModule{
public:
    InitGraphic();
    ~InitGraphic();
};


GENG_END

#endif //MYENGINE_COMPLIE_PREDECLARED_H
