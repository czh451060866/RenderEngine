//
// Created by HongZh on 2022/02/21, 20:55:39
//

#include "render_log.h"
#include <malloc/_malloc.h>

GENG_BEGIN


RenderLog::RenderLog(){
}

RenderLog::~RenderLog(){
    clearLogs();
}

RenderLog & RenderLog::getInstance(){
    static RenderLog instance;
    return instance;
}

// TODO Multithread
void RenderLog::submitLog(const char * fmt, ...){
    std::lock_guard<std::mutex> locker(mtx_);
    uint32_t len;
    char * buf = (char *) malloc(sizeof(char)*256);
    va_list arg;
    va_start(arg, fmt);
    len = vsprintf(buf, fmt, arg);
    log_queue_.emplace_back(buf);
}

std::vector<char*> & RenderLog::getLogs(){
    std::lock_guard<std::mutex> locker(mtx_);
    return log_queue_;
}

void RenderLog::clearLogs(){
    std::lock_guard<std::mutex> locker(mtx_);
    for(auto const & log : log_queue_){
        if(log){
            free(log);
        }
    }
    log_queue_.clear();
}

// void RenderLog::printLog(){
//     std::unique_lock<std::mutex> locker(mtx_, std::defer_lock);
//     while(true){
//         if(is_stop_){
//             printf("unlock11\n");
//             break;
//         }
//         locker.lock();
//         if(log_queue_.empty()){
//             is_empty_.wait(locker);
//         }
//         else{
//             std::string & cur_msg = log_queue_.front();
//             log_queue_.pop();
//             locker.unlock();
//             printf("%s", cur_msg.c_str());
//         }
//     }

// }

GENG_END