//
// Created by zhanghong50 on 2022/2/1.
//

#include "shader_pool.h"
#include "RenderFactory/render_factory.h"
#include "RenderModules/initialization_mod.h"

GENG_BEGIN

ShaderPool::ShaderPool() {
    // initialization
    InitModule::getInstancePtr();
}

ShaderPool::~ShaderPool() {

}

ShaderPool &ShaderPool::getInstance() {
    static ShaderPool instance;
    return instance;
}

// TODO
void ShaderPool::loadShader(const struct ShaderInfo & shader_info) {
    RenderFactory & render_factory = RenderFactory::getInstance();
    std::shared_ptr<ShaderModule> shader = render_factory.assembleShader(shader_info);
    shader_pool_[shader_info.name] = shader;
}

std::shared_ptr<ShaderModule> ShaderPool::getShaderModule(const std::string & name) {
    return shader_pool_[name];
}

GENG_END