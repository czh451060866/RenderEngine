//
// Created by HongZh on 2022/03/08, 18:06:22
//

#include "window_base.h"


namespace window{

WindowBase::WindowBase(){

}

WindowBase::WindowBase(const bool & flag, const std::string & name):
is_open_(flag),
window_name_(name) {

}

WindowBase::~WindowBase(){

}

void WindowBase::openWindow(const bool & flag){
    is_open_ = flag;
}

bool & WindowBase::getWinStatus(){
    return is_open_;
}

}