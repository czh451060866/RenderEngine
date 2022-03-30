//
// Created by zhanghong50 on 2022/1/26.
//

#ifndef MYENGINE_TEXTURE_POOL_H
#define MYENGINE_TEXTURE_POOL_H

#include "general_include.h"
#include "RenderModules/texture_mod.h"

GENG_BEGIN


class TexturePool {
public:
    static TexturePool & getInstance();
    TexturePool(const TexturePool&)=delete;
    TexturePool& operator=(const TexturePool&)=delete;
    ~TexturePool();

    const std::shared_ptr<TextureModule> & getTextureModule(const std::string & name);
    void loadTexture(TextureInfo * tex_info);
private:
    TexturePool();
    std::map<std::string, std::shared_ptr<TextureModule>> texture_;
};

GENG_END

#endif //MYENGINE_TEXTURE_POOL_H
