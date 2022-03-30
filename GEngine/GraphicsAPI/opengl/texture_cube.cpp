//
// Created by HongZh on 2022/03/07, 14:55:51
//

#include "texture_cube.h"
#include "RenderModules/texture_mod.h"
#include "graphic_predeclared.h"
#include "texture_2d.h"

GENG_BEGIN

TextureCube::TextureCube(): Texture2D(){
    tex_dimension_ = GE_TEXTURE_CUBE_MAP;
}

TextureCube::~TextureCube(){

}

void TextureCube::setUpTexture(TextureInfo * tex_info){
    // TODO: handle Exception
    createTextureBuffer();
    bindTexture();
    uint32_t i = 0;
    while(tex_info && i < 6){
        width_ = tex_info->width_;
        height_ = tex_info->height_;
        channel_ = tex_info->channel_;
        type_ = tex_info->type_;
        switch (channel_) {
            case 3: 
                genTexture(GE_TEXTURE_CUBE_MAP_POSITIVE_X + i++, GE_RGB, GE_UBYTE, tex_info->buffer_);
                break;
            case 4:
                genTexture(GE_TEXTURE_CUBE_MAP_POSITIVE_X + i++, GE_RGBA, GE_UBYTE, tex_info->buffer_);
                break;
            default:
                break;
        }
        tex_info = tex_info->next_;
    }
    setTextureParams(GE_CLAMP_TO_BORDER);
    setTextureFilter(GE_LINEAR);
    unbindTexture();
}


void TextureCube::setTextureParams(const GTEX_PARAM & param) {
    glGenerateMipmap(tex_dimension_);
    glTexParameteri(tex_dimension_, GL_TEXTURE_WRAP_S, param);
    glTexParameteri(tex_dimension_, GL_TEXTURE_WRAP_T, param);
    glTexParameteri(tex_dimension_, GL_TEXTURE_WRAP_R, param);
}


void TextureCube::genTexture(const uint32_t & tex_d, const GTEX_T & tex_t, const GData_T & data_t, const uint8_t * buffer) {
    tex_type_ = tex_t;
    glTexImage2D(tex_d, 0, tex_t, width_, height_, 0, tex_t, data_t, buffer);
    // glGenerateMipmap(tex_d);
}





GENG_END