//
// Created by zhanghong50 on 2022/1/19.
//

#include "shader_mod.h"
#include "RenderModules/texture_mod.h"
#include "shader_program.h"

GENG_BEGIN

ShaderModule::ShaderModule() {

}

std::shared_ptr<ShaderModule> ShaderModule::getInstancePtr() {
    std::shared_ptr<ShaderModule> instance_ptr = std::make_shared<ShaderProgram>();
    return instance_ptr;
}

ShaderModule::~ShaderModule() {

}


const std::map<std::string, AttachedTexInfo> & ShaderModule::getTextureInfo(){
    return tex_info_;
}

const std::map<std::string, VariableInfo> & ShaderModule::getUniformInfo(){
    return uniform_info_;
}

const std::map<std::string, VariableInfo> & ShaderModule::getAttribInfo(){
    return attrib_info_;
}


GENG_END