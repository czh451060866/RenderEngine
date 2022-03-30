//
// Created by zhanghong50 on 2022/1/31.
//

#ifndef MYENGINE_RENDER_DATA_H
#define MYENGINE_RENDER_DATA_H

#include "general_include.h"
#include "RenderModules/fbo_mod.h"
#include "RenderModules/texture_mod.h"
#include "RenderModules/data_mod.h"
#include "RenderModules/draw_mod.h"
#include "RenderModules/shader_mod.h"
#include "RenderData/render_parameter.h"

GENG_BEGIN

class RenderData {
public:
    RenderData();
    ~RenderData();

    void setDataModule(std::vector<std::shared_ptr<DataModule>> & data);
    void setTexture(std::shared_ptr<TextureModule> texture);
    void setDrawCall(std::shared_ptr<DrawModule> draw);
    void setShaderProgram(std::shared_ptr<ShaderModule> shader_program);
    void setRenderParam(std::shared_ptr<RenderParam> param);


    std::vector<std::shared_ptr<DataModule>> & getDataModule();
    std::vector<std::shared_ptr<TextureModule>> & getTextures();
    std::shared_ptr<DrawModule> getDrawCall();
    std::shared_ptr<ShaderModule> getShaderProgram();
    std::shared_ptr<RenderParam> getRenderParam();

    //TODO
    void bindFBO();
    void unbindFBO();
    void bindDataModule();
    void unbindDataModule();
    void bindShader();
    void unbindShader();
    void bindTexture();
    void unbindTexture();
    void updateAttribute();
    void updateParams();
    bool isReady();

private:
    std::shared_ptr<FBOModule> fbo_;
    std::shared_ptr<ShaderModule> shader_program_; // shader
    std::vector<std::shared_ptr<DataModule>> data_;    // Data: VAO,VBO,EBO
    std::vector<std::shared_ptr<TextureModule>> textures_;    // texture
    std::shared_ptr<DrawModule> draw_call_;    // draw call
    std::shared_ptr<RenderParam> render_params_;    // render params: uniform variables
};

GENG_END


#endif //MYENGINE_RENDER_DATA_H
