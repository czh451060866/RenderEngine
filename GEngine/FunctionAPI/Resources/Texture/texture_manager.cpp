//
// Created by HongZh on 2022/02/26, 00:18:56
//

#include "texture_manager.h"
#include "RenderModules/texture_mod.h"
#include <memory>

GENG_BEGIN

TextureManager::TextureManager(){
    loader_ = std::make_shared<TextureLoader>();
}

TextureManager::~TextureManager(){
}

TextureInfo * TextureManager::addTexture(const std::string &file, const TextureType & type, TextureInfo * last){
    TextureInfo * texture = loader_->loadTextureFromFile(file, type);
    // all_textures_.push_back(texture);
    // form a linked list 
    if(last != nullptr){
        last->next_ = texture;
    }
    else{
        switch (type)
        {
            case ColorTexture:{
                color_textures_.emplace_back(texture->name_);
                break;
            }
            default: {
                cubemap_textures_.emplace_back(texture->name_);
                break;
            }
        }
    }
    return texture;
}


const std::vector<std::string> & TextureManager::getTextureNames(){
    return color_textures_;
}

const std::vector<std::string> & TextureManager::getCubeMapNames(){
    return cubemap_textures_;
}

void TextureManager::loadTexture(TextureInfo * texture){
    TexturePool & texture_pool = TexturePool::getInstance();
    texture_pool.loadTexture(texture);
    delete texture; // delete textures
    
}


GENG_END