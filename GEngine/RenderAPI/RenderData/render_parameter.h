//
// Created by Hong on 2022/2/12.
//

#ifndef MYENGINE_RENDER_PARAMETER_H
#define MYENGINE_RENDER_PARAMETER_H

#include "data_predeclared.h"
#include "engine_math.h"


GENG_BEGIN

class RenderParam {
public:
    RenderParam();
    ~RenderParam();

    void addParam(const std::string & key, const int32_t & val);
    void addParam(const std::string & key, const float & val);
    // void addParam(std::string key, int32_t* ptr, uint32_t length);
    // void addParam(std::string key, float* ptr, uint32_t length);
   // void addParam(std::string key, GVec2 vals);
    void addParam(const std::string & key, const GVec3 & vals);
   // void addParam(std::string key, GVec4 vals);
    void addParam(const std::string & key, const GMat4 & vals);
    void addParam(const TextureType & types, const std::string & name); // the name of color, normal, Bump, Roughness, Metalic

    // TODO.
    const std::map<TextureType, std::string> & getTextureMap();
    const std::map<std::string, int32_t> & getIntMap();
    const std::map<std::string, float> & getFloatMap();
    const std::map<std::string, GVec3> & getVec3Map();
    const std::map<std::string, GMat4> & getMat4Map();

protected:
    // TODO:
    std::map<TextureType, std::string> texture_params_;
    std::map<std::string, int32_t> int_params_;
    std::map<std::string, float> float_params_;
    // std::map<std::string, std::pair<int32_t *, uint32_t>> int_array_params_;
    // std::map<std::string, std::pair<float*, uint32_t>> float_array_params_;
    std::map<std::string, GVec2> vec2_params_;
    std::map<std::string, GVec3> vec3_params_;
    std::map<std::string, GVec4> vec4_params_;
    std::map<std::string, GMat3> mat3_params_;
    std::map<std::string, GMat4> mat4_params_;
};

GENG_END

#endif //MYENGINE_RENDER_PARAMETER_H
