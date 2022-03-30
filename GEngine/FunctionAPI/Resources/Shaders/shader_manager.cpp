//
// Created by zhanghong50 on 2022/1/28.
//

#include "shader_manager.h"

GENG_BEGIN

ShaderManager::ShaderManager() {
    loader_ = std::make_shared<ShaderLoader>();
}

ShaderManager::~ShaderManager() {

}

void ShaderManager::addShader(const struct ShaderFiles &file) {
    ShaderInfo shader = loader_->loadShaderFile(file);
    loadShader(shader);
    shader_programs_.push_back(file.name);
} 

void ShaderManager::loadShader(const ShaderInfo & shader) {
    ShaderPool & shader_pool = ShaderPool::getInstance();
    shader_pool.loadShader(shader);
}

const std::vector<std::string> & ShaderManager::getEffectName(){
    return shader_programs_;
}

GENG_END
