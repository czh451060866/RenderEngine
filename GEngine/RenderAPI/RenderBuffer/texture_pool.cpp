//
// Created by zhanghong50 on 2022/1/26.
//

#include "texture_pool.h"
#include "RenderFactory/render_factory.h"
#include "RenderModules/texture_mod.h"

GENG_BEGIN

TexturePool::TexturePool(){

}

TexturePool::~TexturePool(){

}

TexturePool & TexturePool::getInstance(){
    static TexturePool instance;
    return instance;
}

const std::shared_ptr<TextureModule> & TexturePool::getTextureModule(const std::string & name){
    return texture_[name];
}

void TexturePool::loadTexture(TextureInfo* tex_info){
    RenderFactory & render_factory = RenderFactory::getInstance();
    std::shared_ptr<TextureModule> texture = render_factory.assembleTexture(tex_info);
    texture_[tex_info->name_] = texture;
}



GENG_END