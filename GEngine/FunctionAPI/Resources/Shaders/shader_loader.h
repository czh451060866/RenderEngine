//
// Created by zhanghong50 on 2022/1/28.
//

#ifndef MYENGINE_SHADER_LOADER_H
#define MYENGINE_SHADER_LOADER_H

#include "Resources/resource_predeclare.h"
#include "RenderBuffer/shader_pool.h"
#include "UserAPI/FileSystem/file_handler_predeclared.h"

GENG_BEGIN

class ShaderLoader {
    std::mutex mtx_;
public:
    ShaderLoader();
    ~ShaderLoader();

    ShaderInfo loadShaderFile(const struct ShaderFiles & file);
};

GENG_END

#endif //MYENGINE_SHADER_LOADER_H
