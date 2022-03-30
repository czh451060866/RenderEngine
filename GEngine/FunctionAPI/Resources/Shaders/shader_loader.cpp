//
// Created by zhanghong50 on 2022/1/28.
//

#include "shader_loader.h"
#include <fstream>
#include <sstream>

GENG_BEGIN

ShaderLoader::ShaderLoader() {
}

ShaderLoader::~ShaderLoader() {
}

ShaderInfo ShaderLoader::loadShaderFile(const struct ShaderFiles & file) {

    std::lock_guard<std::mutex> locker(mtx_);

    ShaderInfo shader_info;
    std::ifstream vertShader;
    std::ifstream fragShader;
    std::stringstream vShaderStream;
    std::stringstream fShaderStream;

    vertShader.open(file.vert_path);
    fragShader.open(file.frag_path);

    vShaderStream << vertShader.rdbuf();
    fShaderStream << fragShader.rdbuf();

    vertShader.close();
    fragShader.close();

    shader_info.vert = vShaderStream.str().c_str();
    shader_info.frag = fShaderStream.str().c_str();
    shader_info.name = file.name;

    return shader_info;
}


GENG_END