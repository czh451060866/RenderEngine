//
// Created by zhanghong50 on 2022/1/31.
//

#include "render_data.h"
#include "RenderBuffer/texture_pool.h"
#include "RenderModules/status_mod.h"
#include "RenderModules/texture_mod.h"


GENG_BEGIN

RenderData::RenderData() {
    shader_program_ = nullptr;
    draw_call_ = nullptr;
    render_params_ = nullptr;
}

RenderData::~RenderData() {

}

void RenderData::setDrawCall(std::shared_ptr<DrawModule> draw) {
    draw_call_ = draw;
}

void RenderData::setTexture(std::shared_ptr<TextureModule> texture) {
    textures_.push_back(texture);
}

void RenderData::setDataModule(std::vector<std::shared_ptr<DataModule>> &data) {
    data_ = data;
}

void RenderData::setShaderProgram(std::shared_ptr<ShaderModule> shader_program) {
    shader_program_ = shader_program;
}

void RenderData::setRenderParam(std::shared_ptr<RenderParam> param) {
    render_params_ = param;
}

std::vector<std::shared_ptr<DataModule>> &RenderData::getDataModule() {
    return data_;
}

std::vector<std::shared_ptr<TextureModule>> &RenderData::getTextures() {
    return textures_;
}

std::shared_ptr<DrawModule> RenderData::getDrawCall() {
    return draw_call_;
}

std::shared_ptr<ShaderModule> RenderData::getShaderProgram() {
    return shader_program_;
}

std::shared_ptr<RenderParam> RenderData::getRenderParam() {
    return render_params_;
}

bool RenderData::isReady(){
    return shader_program_ && !data_.empty() && draw_call_;
}

void RenderData::bindShader(){
    shader_program_->bindProgram();
}

void RenderData::unbindShader(){
    shader_program_->unbindProgram();
}

void RenderData::bindTexture(){
    // TODO
    auto const & texture_info = shader_program_->getTextureInfo();
    const std::map<TextureType, std::string> & tex_map = render_params_->getTextureMap();
    TexturePool & texture_pool = TexturePool::getInstance();
    for(auto const & [var_name, info]: texture_info){
        if(tex_map.find(info.type_) != tex_map.end()){
            auto tex = texture_pool.getTextureModule(tex_map.at(info.type_));  // TODO
            if(tex)
                shader_program_->setUniformTexture(var_name, tex);
        }
    }

}

void RenderData::unbindTexture(){
  auto const & texture_info = shader_program_->getTextureInfo();
    const std::map<TextureType, std::string> & tex_map = render_params_->getTextureMap();
    TexturePool & texture_pool = TexturePool::getInstance();
    for(auto const & [var_name, info]: texture_info){
        if(tex_map.find(info.type_) != tex_map.end()){
            auto tex = texture_pool.getTextureModule(tex_map.at(info.type_));  // TODO
            if(tex)
                tex->unbindTexture();
        }
    }
}

void RenderData::updateParams(){

    auto const & uniform_info = shader_program_->getUniformInfo();
    // float
    auto & float_map = render_params_->getFloatMap();
    for(auto const& iter :float_map){
        shader_program_->setUniform1f(iter.first, iter.second);
    }
    // vec3
    auto & vec3_map = render_params_->getVec3Map();
    for(auto const& iter :vec3_map){
        shader_program_->setUniformVec3(iter.first, iter.second);
    }
    // mat4
    auto & mat4_map = render_params_->getMat4Map();
    for(auto const& iter : mat4_map){
        shader_program_->setUniformMat4f(iter.first, iter.second);
    }
}

void RenderData::updateAttribute(){
    for(const auto & data_entry : data_){
        switch (data_entry->getDataLayOut())
        {
        case VERTEX_POSITION:{
            data_entry->setUpLayout(shader_program_->getPosLocation());
            break;
        }
        case VERTEX_NORMAL:{
            data_entry->setUpLayout(shader_program_->getNormLocation());
            break;
        }
        case VERTEX_TANGENT:{
            data_entry->setUpLayout(shader_program_->getTangentLocation());
            break;
        }
        case VERTEX_BITANGENT:{
            data_entry->setUpLayout(shader_program_->getBitangentLocation());
            break;
        }
        case TEXTURE_COORDINATE:{
            data_entry->setUpLayout(shader_program_->getUVLocation());
            break;
        }
        default:
            break;
        }
    }
}

void RenderData::bindFBO(){
    if(fbo_)
        fbo_->bindFBO();
}

void RenderData::unbindFBO(){
    if(fbo_)
        fbo_->unbindFBO();
}

void RenderData::bindDataModule() {
    for(auto data_mod: data_){
        if(data_mod->getBufferType() == "ARRAY_BUFFER"){
            data_mod->bindDataBuffer();
            data_mod->enableVAA();
        }
        else if(data_mod->getBufferType() == "ELEMENT_ARRAY_BUFFER"){
            data_mod->bindDataBuffer();
        }
    }
}

void RenderData::unbindDataModule() {
    for(auto data_mod: data_){
        if(data_mod->getBufferType() == "ARRAY_BUFFER"){
            data_mod->unbindDataBuffer();
            data_mod->disableVAA();
        }
        else if(data_mod->getBufferType() == "ELEMENT_ARRAY_BUFFER"){
            data_mod->unbindDataBuffer();
        }
    }
}





GENG_END
