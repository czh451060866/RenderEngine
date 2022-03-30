//
// Created by HongZh on 2022/03/24, 16:05:06
//

#include "scene_setting.h"

GENG_BEGIN

SceneSetting::SceneSetting(){

}

SceneSetting::~SceneSetting(){

}

const bool & SceneSetting::isEnableShadow(){
    return enable_shadow_;
}

const bool & SceneSetting::isEnableSoftShadow(){
    return is_soft_shadow_;
}

void SceneSetting::EnableShadow(const bool & flag){
    enable_shadow_ = flag;
}

void SceneSetting::EnableSoftShadow(const bool &flag){
    is_soft_shadow_ = flag;
}


GENG_END