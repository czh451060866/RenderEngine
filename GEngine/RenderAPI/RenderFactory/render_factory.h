//
// Created by zhanghong50 on 2022/1/29.
//

#ifndef MYENGINE_RENDER_FACTORY_H
#define MYENGINE_RENDER_FACTORY_H
#include "RenderBuffer/texture_pool.h"
#include "general_include.h"
#include "RenderModules/data_mod.h"
#include "RenderModules/shader_mod.h"
#include "RenderModules/texture_mod.h"

GENG_BEGIN

class RenderFactory {
private:
    RenderFactory();
public:
    ~RenderFactory();
    static RenderFactory & getInstance();

    std::shared_ptr<ShaderModule> assembleShader(const struct ShaderInfo & shader_info);
    std::shared_ptr<DataModule> assembleData(const std::vector<float> & data);
    std::shared_ptr<DataModule> assembleData(const std::vector<uint32_t> & data);
    std::shared_ptr<TextureModule> assembleTexture(TextureInfo * tex_info);

};

GENG_END

#endif //MYENGINE_RENDER_FACTORY_H
