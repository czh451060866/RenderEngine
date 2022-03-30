//
// Created by zhanghong50 on 2022/1/19.
//

#include "texture_mod.h"
#include "texture_2d.h"
#include "texture_cube.h"

GENG_BEGIN

TextureModule::TextureModule() {

}

TextureModule::~TextureModule() {

}

std::shared_ptr<TextureModule> TextureModule::getInstancePtr(const TextureType & type){
    std::shared_ptr<TextureModule> tex_mod; 
    switch (type) {
        case CubeMapTexture:{   
            tex_mod = std::make_shared<TextureCube>();
            break;
        }
        default:{
            tex_mod = std::make_shared<Texture2D>();
            break;
        }
    }
    return tex_mod;
}



GENG_END

