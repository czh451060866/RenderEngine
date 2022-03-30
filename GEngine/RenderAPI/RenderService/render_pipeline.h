//
// Created by zhanghong50 on 2022/1/28.
//

#ifndef MYENGINE_RENDER_PIPELINE_H
#define MYENGINE_RENDER_PIPELINE_H

#include "general_include.h"
#include "RenderAPI/RenderQueue/render_data.h"

GENG_BEGIN

// TODO: multi_thread

class RenderPipeline {
public:
    RenderPipeline();
    ~RenderPipeline();
    void startRender();
    void setRenderData(std::shared_ptr<RenderData> render_data);
private:
    std::shared_ptr<RenderData> render_data_;    // loaded data
    std::mutex mtx_;    // mutex
};
GENG_END


#endif //MYENGINE_RENDER_PIPELINE_H
