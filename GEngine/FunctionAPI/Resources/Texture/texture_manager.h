//
// Created by HongZh on 2022/02/26, 00:09:24
//

#ifndef MYENGINE_TEXTURE_MANAGER_H
#define MYENGINE_TEXTURE_MANAGER_H


#include "RenderModules/texture_mod.h"
#include "texture_loader.h"

GENG_BEGIN

class TextureManager{
public:
    TextureManager();
    ~TextureManager();

    TextureInfo * addTexture(const std::string & file, const TextureType & type = ColorTexture, TextureInfo * last = nullptr);
    void loadTexture(TextureInfo * texture);
    const std::vector<std::string> & getTextureNames();
    const std::vector<std::string> & getCubeMapNames();
    
private:
    // std::vector<TextureInfo *> all_textures_;
    std::vector<std::string> color_textures_;
    std::vector<std::string> cubemap_textures_;
    std::vector<std::string> normal_textures_;

    std::shared_ptr<TextureLoader> loader_;
};

GENG_END

#endif //MYENGINE_TEXTURE_MANAGER_H