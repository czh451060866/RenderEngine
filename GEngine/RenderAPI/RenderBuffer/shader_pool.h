//
// Created by zhanghong50 on 2022/2/1.
//

#ifndef MYENGINE_SHADER_POOL_H
#define MYENGINE_SHADER_POOL_H

#include "general_include.h"
#include "RenderModules/shader_mod.h"

GENG_BEGIN

class ShaderPool {
public:
    static ShaderPool & getInstance();
    ShaderPool(const ShaderPool&)=delete;
    ShaderPool& operator=(const ShaderPool&)=delete;
    ~ShaderPool();

    void loadShader(const struct ShaderInfo & shader_info);
    std::shared_ptr<ShaderModule> getShaderModule(const std::string & name);
private:
    std::map<std::string, std::shared_ptr<ShaderModule>> shader_pool_;
    ShaderPool();

};

GENG_END


#endif //MYENGINE_SHADER_POOL_H
