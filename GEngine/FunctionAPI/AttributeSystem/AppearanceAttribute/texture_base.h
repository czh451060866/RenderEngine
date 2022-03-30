//
// Created by HongZh on 2022/03/20, 11:17:43
//

#ifndef MYENGINE_TEXTURE_BASE_H
#define MYENGINE_TEXTURE_BASE_H

#include "AttributeSystem/attribute_base.h"

GENG_BEGIN
class TextureBase : public AttributeBase{
public:
    TextureBase();
    ~TextureBase();
    void setObjectColor(const GVec3 & color);
    void setColorTexture(const std::string & tex_name);
    void setNormalTexture(const std::string & tex_name);
    void setCubeMapTexture(const std::string & tex_name);
    
    const GVec3 & getObjectColor();
    const std::string & getColorTexture();
    const std::string & getNormalTexture();
    const std::string & getCubeMapTexture();

private:
    GVec3 object_color_ = GVec3(1.0f);
    std::string color_textures_;
    std::string normal_textures_;
    std::string cubemap_textures_;
};
GENG_END

#endif //MYENGINE_TEXTURE_BASE_H