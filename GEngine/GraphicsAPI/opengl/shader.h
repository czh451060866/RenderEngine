//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_SHADER_H
#define MYENGINE_SHADER_H

#include "graphic_predeclared.h"
#include "RenderModules/shader_mod.h"

GENG_BEGIN

class Shader {
public:
    Shader(GSHADER_T type);
    ~Shader();

    // shader
    virtual void createShader();
    virtual void linkShaderSource(const char* data, int32_t length);
    virtual void compileShader();
    virtual void getShaderStatus();
    virtual void deleteShader();
public:
    GLuint shader_id_;
    GSHADER_T type_;

};

GENG_END

#endif //MYENGINE_SHADER_H
