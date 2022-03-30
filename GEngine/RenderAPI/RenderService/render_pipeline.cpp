//
// Created by zhanghong50 on 2022/1/28.
//

#include "render_pipeline.h"

GENG_BEGIN

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline(){

}

void RenderPipeline::startRender(void) {
    std::lock_guard<std::mutex> lock(mtx_);

    if(!render_data_->isReady()){
        return;
    }
    // fbo
    render_data_->bindFBO();
    // shader
    render_data_->bindShader();
    // texture
    render_data_->bindTexture();
    // attribute
    render_data_->updateAttribute();
    //param
    render_data_->updateParams();
    // VBO
    render_data_->bindDataModule();
    // draw element
    render_data_->getDrawCall()->drawElement();
    // data mod
    render_data_->unbindDataModule();
    // texture
    render_data_->unbindTexture();
    // shader
    render_data_->unbindShader();
    // fbo
    render_data_->unbindFBO();
}



void RenderPipeline::setRenderData(std::shared_ptr<RenderData> render_data) {
    std::lock_guard<std::mutex> lock(mtx_);
    render_data_ = render_data;
}


GENG_END