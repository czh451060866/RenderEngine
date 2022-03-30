//
// Created by zhanghong50 on 2022/1/29.
//

#include "render_factory.h"
#include "RenderBuffer/texture_pool.h"
#include "RenderModules/data_mod.h"


GENG_BEGIN

RenderFactory::RenderFactory() {

}

RenderFactory::~RenderFactory() {

}

RenderFactory & RenderFactory::getInstance() {
    static RenderFactory instance;
    return instance;
}

std::shared_ptr<ShaderModule> RenderFactory::assembleShader(const struct ShaderInfo & shader_info) {
    std::shared_ptr<ShaderModule> program =  ShaderModule::getInstancePtr();
    program->linkVertShader(shader_info.vert.c_str(), shader_info.vert.length());
    program->linkFragShader(shader_info.frag.c_str(), shader_info.frag.length());
    program->setUpProgram(shader_info.name);
    return program;
}

std::shared_ptr<DataModule> RenderFactory::assembleData(const std::vector<float> & data) {
    std::shared_ptr<DataModule> data_mod = DataModule::getInstancePtr();
    data_mod->setUpFloatData(& data[0], data.size());
    return data_mod;
}

std::shared_ptr<DataModule> RenderFactory::assembleData(const std::vector<uint32_t> &data) {
    std::shared_ptr<DataModule> data_mod = DataModule::getInstancePtr();
    data_mod->setUpIntData(& data[0], data.size());
    return data_mod;
}

std::shared_ptr<TextureModule> RenderFactory::assembleTexture(TextureInfo * tex_info){
    std::shared_ptr<TextureModule> tex_mod = TextureModule::getInstancePtr(tex_info->type_);
    tex_mod->setUpTexture(tex_info);
    return tex_mod;
}

GENG_END
