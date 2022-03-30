//
// Created by HongZh on 2022/03/23, 17:52:21
//

#ifndef MYENGINE_SELECTED_COMBO_PLUGIN_H
#define MYENGINE_SELECTED_COMBO_PLUGIN_H

#include "plugin_base.h"

namespace window {

class SelectedComboPlugin: public PluginBase{
public:
    SelectedComboPlugin(const std::string & name);
    ~SelectedComboPlugin();
    void showPlugin(const std::vector<std::string> & names);
private:
    void (*doActionFunc)(const std::string &, const std::string &);
    std::string selected_item_;
};

}

#endif //MYENGINE_SELECTED_COMBO_PLUGIN_H