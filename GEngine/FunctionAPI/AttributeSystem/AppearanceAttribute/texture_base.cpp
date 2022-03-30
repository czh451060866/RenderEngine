//
// Created by HongZh on 2022/03/20, 11:20:53
//

#include "texture_base.h"

GENG_BEGIN

TextureBase::TextureBase(){

}

TextureBase::~TextureBase(){
    
}

const GVec3 & TextureBase::getObjectColor(){
    return object_color_;
}

void TextureBase::setObjectColor(const GVec3 &color){
    object_color_ = color;
}

void TextureBase::setColorTexture(const std::string &tex_name){
    color_textures_ = tex_name;
}

void TextureBase::setNormalTexture(const std::string &tex_name){
    normal_textures_ = tex_name;
}

void TextureBase::setCubeMapTexture(const std::string &tex_name){
    cubemap_textures_ = tex_name;
}

const std::string & TextureBase::getColorTexture(){
    return color_textures_;
}

const std::string & TextureBase::getCubeMapTexture(){
    return cubemap_textures_;
}

const std::string & TextureBase::getNormalTexture(){
    return normal_textures_;
}

GENG_END