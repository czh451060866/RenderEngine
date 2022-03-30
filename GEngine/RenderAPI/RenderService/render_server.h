//
// Created by zhanghong50 on 2022/1/27.
//

#ifndef MYENGINE_RENDER_SERVER_H
#define MYENGINE_RENDER_SERVER_H

#include "RenderAPI/RenderData/render_node.h"
#include "RenderQueue/render_queue.h"
#include "RenderFactory/render_factory.h"
#include "RenderBuffer/fbo_pool.h"
#include "render_pipeline.h"
#include "RenderData/render_integrator.h"
#include "RenderData/render_mesh.h"
#include "RenderModules/status_mod.h"

GENG_BEGIN

// TODO
class RenderServer {
public:
    explicit RenderServer(std::shared_ptr<RenderSystem> render_system);
    ~RenderServer();
    RenderServer(const RenderServer &) = delete;
    RenderServer & operator= (const RenderServer &) = delete;

    void prepareRenderNode(std::shared_ptr<RenderNode> node);    // functions
    void setResourceSystem(std::shared_ptr<RenderSystem> render_system);
    void startRenderService();

private:
    // FBOPool * fbo_pool_; // fbo
    std::vector<uint32_t> fbo_id_;

    RenderQueue render_queue_;    // render queue
    RenderPipeline render_pip_;    // render pipeline
    RenderIntegrator render_integrator_;    // render integrator
    StatusManager status_manager_;
    std::shared_ptr<RenderSystem> render_system_ptr_;

    void beforeRender();    // TODO
    void startRender();// render related
};

GENG_END


#endif //MYENGINE_RENDER_SERVER_H
