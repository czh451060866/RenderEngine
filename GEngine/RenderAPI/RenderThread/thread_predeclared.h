//
// Created by zhanghong50 on 2022/1/24.
//

#ifndef MYENGINE_THREAD_PRECLARED_H
#define MYENGINE_THREAD_PRECLARED_H

#include "general_include.h"
#include <thread>
#include <atomic>

GENG_BEGIN

static uint32_t MAX_LIMIT_NUM_THREAD = std::thread::hardware_concurrency();

#define MAX_NUM_THREAD 20

GENG_END

#endif //MYENGINE_THREAD_PRECLARED_H
