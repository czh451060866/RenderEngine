//
// Created by zhanghong50 on 2022/1/28.
//

#ifndef MYENGINE_INITIALIZATION_MOD_H
#define MYENGINE_INITIALIZATION_MOD_H

#include "general_include.h"

GENG_BEGIN

class InitModule {
protected:
    InitModule();
public:
    static std::shared_ptr<InitModule> & getInstancePtr();
    InitModule(const InitModule &) = delete;
    InitModule & operator = (const InitModule &) = delete;
    virtual ~InitModule();
};

GENG_END


#endif //MYENGINE_INITIALIZATION_MOD_H
