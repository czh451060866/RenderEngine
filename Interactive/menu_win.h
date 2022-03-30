//
// Created by HongZh on 2022/03/24, 23:15:54
//

#ifndef MYENGINE_MENU_WIN_H
#define MYENGINE_MENU_WIN_H

#include "window_base.h"


namespace window {

class MenuWindow: public WindowBase{
public:
    MenuWindow();
    ~MenuWindow();
    void showWindow(...) override;
protected:
    uint32_t width_;
    uint32_t height_;
};

}

#endif //MYENGINE_MENU_WIN_H