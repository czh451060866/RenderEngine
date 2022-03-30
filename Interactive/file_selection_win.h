//
// Created by HongZh on 2022/03/08, 11:11:17
//

#ifndef MYENGINE_FILE_SELECTION_WIN_H
#define MYENGINE_FILE_SELECTION_WIN_H

#include "window_base.h"

namespace window {

class FileSelectionWindow : public WindowBase{
private:
    std::string cur_path_;
    std::string selected_item_;

    bool loadCurrentFiles(std::string & path);
public:
    FileSelectionWindow();
    FileSelectionWindow(std::string name);
    ~FileSelectionWindow();

    void showWindow(...) override;
    const std::string getSelectedItem();
};

}
#endif //MYENGINE_FILE_SELECTION_WIN_H