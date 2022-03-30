//
// Created by Hong on 2022/2/12.
//

#include "render_parameter.h"
#include "RenderModules/texture_mod.h"
#include <string>

GENG_BEGIN


RenderParam::RenderParam() {

}

RenderParam::~RenderParam() {

}

void RenderParam::addParam(const std::string & key, const int32_t & val) {
    int_params_[key] = val;
}

void RenderParam::addParam(const std::string & key, const float & val) {
    float_params_[key] = val;
}

void RenderParam::addParam(const TextureType & key, const std::string & tex_name){
    texture_params_[key] = tex_name;
}
// void RenderParam::addParam(std::string key, int32_t *ptr, uint32_t length) {
//     int_array_params_[key] = std::make_pair(ptr, length);
// }

// void RenderParam::addParam(std::string key, float *ptr, uint32_t length) {
//     float_array_params_[key] = std::make_pair(ptr, length);
// }

void RenderParam::addParam(const std::string & key, const GVec3 & vals) {
    vec3_params_[key] = vals;
}

void RenderParam::addParam(const std::string & key, const GMat4 & vals) {
    mat4_params_[key] = vals;
}

const std::map<TextureType, std::string> & RenderParam::getTextureMap() {
    return texture_params_;
}

const std::map<std::string, int> & RenderParam::getIntMap() {
    return int_params_;
}

const std::map<std::string, float> & RenderParam::getFloatMap() {
    return float_params_;
}

const std::map<std::string, GVec3> & RenderParam::getVec3Map() {
    return vec3_params_;
}

const std::map<std::string, GMat4> & RenderParam::getMat4Map() {
    return mat4_params_;
}

GENG_END
