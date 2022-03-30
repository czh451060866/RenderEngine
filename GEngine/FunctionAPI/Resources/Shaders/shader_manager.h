//
// Created by zhanghong50 on 2022/1/28.
//

#ifndef MYENGINE_SHADER_MANAGER_H
#define MYENGINE_SHADER_MANAGER_H

#include "shader_loader.h"

GENG_BEGIN

class ShaderManager {
public:
    ShaderManager();
    ~ShaderManager();

    void addShader(const struct ShaderFiles & files);
    const std::vector<std::string> & getEffectName();
private:
    std::vector<std::string> shader_programs_;
    std::shared_ptr<ShaderLoader> loader_;

    void loadShader(const ShaderInfo & shader_);
};

GENG_END
#endif //MYENGINE_SHADER_MANAGER_H
