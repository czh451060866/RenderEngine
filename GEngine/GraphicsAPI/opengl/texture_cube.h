//
// Created by HongZh on 2022/03/07, 14:48:18
//

#ifndef MYENGINE_TEXTURE_CUBE_H
#define MYENGINE_TEXTURE_CUBE_H

#include "graphic_predeclared.h"
#include "texture_2d.h"

GENG_BEGIN

class TextureCube: public Texture2D{
public:
    TextureCube();
    ~TextureCube();
    void setUpTexture(TextureInfo * tex_info) override;
    void setTextureParams(const GTEX_PARAM & param) override;
    void genTexture(const uint32_t & tex_d, const GTEX_T & tex_t, const GData_T & data_t, const uint8_t * buffer) override;

};

GENG_END

#endif //MYENGINE_TEXTURE_CUBE_H