//
// Created by HongZh on 2022/03/10, 11:44:08
//

#ifndef MYENGINE_LOG_WIN_H
#define MYENGINE_LOG_WIN_H

#include "window_base.h"

namespace window {

#define MAX_LENGTH_OF_BUFFER 1000

class LogWindow : public WindowBase {
public:
    LogWindow();
    ~LogWindow();

    void clear();
    void addLog();
    void showWindow(...) override;
private:
    bool auto_scroll_;
    uint8_t * buffer_;
    uint32_t num_of_log_;
    uint32_t len_of_log_;
    std::vector<uint32_t> log_offset;
    std::vector<char*> buffers_;
};

}

#endif //MYENGINE_LOG_WIN_H