//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_TEXTURE_H
#define MYENGINE_TEXTURE_H

#include "graphic_predeclared.h"
#include "RenderModules/texture_mod.h"

GENG_BEGIN

class Texture2D: public TextureModule{
public:
    GLuint tex_id_;
    GTEX_D tex_dimension_;
    GTEX_T tex_type_; // color, depth, stencil
    uint32_t unit_id_;
public:
    Texture2D();
    virtual ~Texture2D();
    virtual void createTextureBuffer() override;

    // TODO: 2D texture only now
    virtual void bindTexture() override;
    virtual void unbindTexture() override;
    virtual void activeTexture(const uint32_t & unit_id) override;
    virtual void setUpTexture(TextureInfo * tex_info) override;

    // set texture parameters
    virtual void setTextureParams(const GTEX_PARAM & param);
    // set texture filtering
    virtual void setTextureFilter(const GTEX_PARAM & param);

    // generate a texture
    virtual void genTexture(const uint32_t & tex_d, const GTEX_T & tex_t, const GData_T & data_t, const uint8_t * buffer = nullptr);
    virtual void deleteTexture();

};

GENG_END

#endif //MYENGINE_TEXTURE_H
