//
// Created by zhanghong50 on 2022/1/13.
//

#include "texture_2d.h"
#include "RenderModules/texture_mod.h"
#include "graphic_predeclared.h"

GENG_BEGIN

Texture2D::Texture2D(): tex_id_(-1), tex_dimension_(GE_TEXTURE_2D), unit_id_(0) {

}
Texture2D::~Texture2D() {

}

void Texture2D::setUpTexture(TextureInfo * tex_info){
    createTextureBuffer();
    bindTexture();
    width_ = tex_info->width_;
    height_ = tex_info->height_;
    channel_ = tex_info->channel_;
    type_ = tex_info->type_;
    switch (channel_) {
        case 3: 
            genTexture(tex_dimension_, GE_RGB, GE_UBYTE, tex_info->buffer_);
            break;
        case 4:
            genTexture(tex_dimension_, GE_RGBA, GE_UBYTE, tex_info->buffer_);
            break;
        default:
            break;
    }
   
    setTextureParams(GE_CLAMP_TO_BORDER);
    setTextureFilter(GE_LINEAR);
    unbindTexture();
}

void Texture2D::createTextureBuffer() {
    glGenTextures(1, &tex_id_);
}

void Texture2D::bindTexture() {
    glBindTexture(tex_dimension_, tex_id_);
}

void Texture2D::activeTexture(const uint32_t & unit_id) {
    unit_id_ = unit_id;
    glActiveTexture(GL_TEXTURE0 + unit_id_);
}

void Texture2D::unbindTexture() {
    glBindTexture(tex_dimension_, 0);
}

void Texture2D::setTextureParams(const GTEX_PARAM & param) {
    glGenerateMipmap(tex_dimension_);
    glTexParameteri(tex_dimension_, GL_TEXTURE_WRAP_S, param);
    glTexParameteri(tex_dimension_, GL_TEXTURE_WRAP_T, param);
}

void Texture2D::setTextureFilter(const GTEX_PARAM & param) {
    glTexParameteri(tex_dimension_, GL_TEXTURE_MIN_FILTER, param);
    glTexParameteri(tex_dimension_, GL_TEXTURE_MAG_FILTER, param);
}


void Texture2D::genTexture(const uint32_t & tex_d, const GTEX_T & tex_t, const GData_T & data_t, const uint8_t * buffer) {
    tex_type_ = tex_t;
    glTexImage2D(tex_d, 0, tex_t, width_, height_, 0, tex_t, data_t, buffer);
}

void Texture2D::deleteTexture() {
    if(tex_id_ != -1){
        glDeleteTextures(1, & tex_id_);
    }
}


GENG_END
