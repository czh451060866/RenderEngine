//
// Created by HongZh on 2022/02/21, 20:38:58
//

#ifndef MYENGINE_RENDER_LOG
#define MYENGINE_RENDER_LOG

#include "general_include.h"

GENG_BEGIN

class RenderLog{
private:
     // std::queue<std::string> log_queue_;
     std::vector<char * > log_queue_;
     std::mutex mtx_;
     std::condition_variable is_empty_;
     // bool is_stop_;
     
     RenderLog();
     // void printLog();
public:
     static RenderLog & getInstance();
     RenderLog(const RenderLog &) = delete;
     RenderLog & operator = (const RenderLog &) = delete;
     ~RenderLog();

     void clearLogs();
     void submitLog(const char * fmt, ...); // formated char*
     std::vector<char*> & getLogs();
};

GENG_END

#endif //MYENGINE_RENDER_LOG