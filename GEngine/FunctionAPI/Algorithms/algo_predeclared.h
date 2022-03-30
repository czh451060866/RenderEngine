//
// Created by HongZh on 2022/03/11, 11:04:43
//

#ifndef MYENGINE_ALGO_PREDECLARED_H
#define MYENGINE_ALGO_PREDECLARED_H

#include "general_include.h"
#include "engine_math.h"
#include "RenderThread/engine_thread_pool.h"
#include "RenderLog/render_log.h"
#include <chrono>
#include <ratio>

GENG_BEGIN

#define DEBUG
#ifdef DEBUG
using namespace std::chrono;

class GTimer{
    std::string task_;
    time_point<high_resolution_clock> t_begin_;
    time_point<high_resolution_clock> t_end_;
public:
    explicit GTimer(const std::string & task_name){
        task_ = std::move(task_name);
        t_begin_ = high_resolution_clock::now();
    }
    ~GTimer(){
        t_end_ = high_resolution_clock::now();
        RenderLog & render_log = RenderLog::getInstance();
        render_log.submitLog("%s costs %f ms.\n", task_.c_str(), duration_cast<microseconds>(t_end_ - t_begin_).count()/1000.0);
    }
    GTimer(const GTimer &) = delete;
    GTimer & operator =(const GTimer &) = delete;
};

#endif // DEBUG
GENG_END

#endif //MYENGINE_ALGO_PREDECLARED_H