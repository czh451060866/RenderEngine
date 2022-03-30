//
// Created by HongZh on 2022/03/08, 18:00:31
//

#ifndef MYENGINE_WINDOW_BASE_H
#define MYENGINE_WINDOW_BASE_H

#include "window_predeclared.h"


namespace window {

class WindowBase{
public:
    WindowBase();
    WindowBase(const bool & is_open, const std::string & name);
    ~WindowBase();

    bool & getWinStatus();
    virtual void showWindow(...) = 0; 
    virtual void openWindow(const bool & flag = true);

protected:
    bool is_open_;
    std::string window_name_;
    std::mutex mtx_;
};

}

#endif //MYENGINE_WINDOW_BASE_H