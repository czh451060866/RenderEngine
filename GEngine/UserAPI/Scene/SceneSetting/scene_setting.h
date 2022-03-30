//
// Created by HongZh on 2022/03/24, 16:01:28
//

#ifndef MYENGINE_SCENE_SETTING_H
#define MYENGINE_SCENE_SETTING_H

#include "Scene/scene_predeclared.h"

GENG_BEGIN

class SceneSetting{
public:
    SceneSetting();
    ~SceneSetting();
    
    void EnableShadow(const bool & flag);
    void EnableSoftShadow(const bool & flag);
    const bool & isEnableShadow();
    const bool & isEnableSoftShadow();
private:
    bool is_soft_shadow_ = false;  // TODO: single class 
    bool enable_shadow_ = false;
};

GENG_END

#endif //MYENGINE_SCENE_SETTING_H