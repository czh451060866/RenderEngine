//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_TEXTURE_MOD_H
#define MYENGINE_TEXTURE_MOD_H

#include "general_include.h"
GENG_BEGIN

class TextureInfo{
public:
    uint8_t * buffer_ = nullptr;
    int32_t width_ = 0;
    int32_t height_ = 0;
    int32_t channel_ = 0;
    TextureType type_ = ColorTexture;
    std::string name_ = "";
    TextureInfo* next_ = nullptr;
    TextureInfo();
    ~TextureInfo();
};

class TextureModule {
public:
    static std::shared_ptr<TextureModule> getInstancePtr(const TextureType & type);
    virtual ~TextureModule();

    virtual void createTextureBuffer() = 0;
    virtual void bindTexture() = 0;
    virtual void unbindTexture() = 0;
    virtual void activeTexture(const uint32_t & unit_id) = 0;
    virtual void setUpTexture(TextureInfo * tex_info) = 0;
protected:
    TextureModule();
    TextureType type_;
    bool is_loaded_ = false;
    uint32_t width_ = 0;
    uint32_t height_ = 0;
    uint32_t channel_ = 0;
};

GENG_END


#endif //MYENGINE_TEXTURE_MOD_H
