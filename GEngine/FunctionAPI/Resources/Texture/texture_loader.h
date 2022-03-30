//
// Created by HongZh on 2022/02/25, 23:33:01
//

#ifndef MYENGINE_TEXTURE_LOADER_H
#define MYENGINE_TEXTURE_LOADER_H

#include "RenderModules/texture_mod.h"
#include "Resources/resource_predeclare.h"
#include "RenderBuffer/texture_pool.h"

GENG_BEGIN

class TextureLoader{
private:
    std::map<TextureType, uint32_t> tex_id_;
public:
    TextureLoader();
    ~TextureLoader(); 

    TextureInfo* loadTextureFromFile(const std::string & file, TextureType type = ColorTexture);
    
};

GENG_END

#endif //MYENGINE_TEXTURE_LOADER_H