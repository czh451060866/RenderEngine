//
// Created by HongZh on 2022/02/25, 23:39:17
//

#include "texture_loader.h"
#include "RenderModules/texture_mod.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

GENG_BEGIN

TextureInfo::TextureInfo(){

}

TextureInfo::~TextureInfo(){
    if(buffer_){
        delete buffer_;
    }
    buffer_ = nullptr;
    
    // delete all the rests of textures
   if(next_ != nullptr){
       delete next_;
   }
}

TextureLoader::TextureLoader(){

}

TextureLoader::~TextureLoader(){

}

TextureInfo * TextureLoader::loadTextureFromFile(const std::string & file, TextureType type){
    TextureInfo* texture = new TextureInfo();
    // TODO: exception handler
    stbi_set_flip_vertically_on_load(true);
    texture->buffer_ = stbi_load(file.c_str(), &texture->width_, &texture->height_, &texture->channel_, 0);
    if(tex_id_.find(type) == tex_id_.end()){
        tex_id_[type] = 0;
    }
    texture->name_ = tex_prefix.at(type) + std::to_string(tex_id_.at(type)++);
    texture->type_ = type;
    return texture;
}

GENG_END