//
// Created by HongZh on 2022/03/23, 17:57:17
//

#ifndef MYENGINE_PLUGIN_BASE_H
#define MYENGINE_PLUGIN_BASE_H

#include "window_base.h"

namespace window {
class PluginBase{
public:
    explicit PluginBase(const std::string & name);
    ~PluginBase();
protected:
    std::string plugin_name_;
};
}

#endif //MYENGINE_PLUGIN_BASE_H