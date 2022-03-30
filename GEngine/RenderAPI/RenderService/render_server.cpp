//
// Created by zhanghong50 on 2022/1/27.
//

#include "render_server.h"
#include "RenderModules/initialization_mod.h"
#include "RenderThread/engine_thread_pool.h"
#include "RenderLog/render_log.h"

GENG_BEGIN

RenderServer::RenderServer(std::shared_ptr<RenderSystem> render_system):
render_system_ptr_(render_system) {
    // thread_pool_ = & ThreadPool::getInstance();
    // fbo_pool_ = & FBOPool::getInstance();

    // initialization
    InitModule::getInstancePtr();
    ThreadPool & thread_pool = ThreadPool::getInstance();
    
    // set render system 
    render_integrator_.setRenderSystem(render_system);
    // RenderLog & render_log = RenderLog::getInstance();

    // render_log.submitLog("Start RenderService!!\n");
}


RenderServer::~RenderServer() {

}


void RenderServer::prepareRenderNode(std::shared_ptr<RenderNode> node) {
    render_integrator_.processRenderNode(node);
}

void RenderServer::beforeRender() {
    // clear the render queue
    render_queue_.emptyQueue();
    render_integrator_.buildRenderQueue(render_queue_);
}

void RenderServer::startRender() {
    while(!render_queue_.isEmpty()){

        std::shared_ptr<RenderData> render_data = render_queue_.queryAndPopQueue();

        render_pip_.setRenderData(render_data);
        render_pip_.startRender();
    }

}


void RenderServer::startRenderService() {
    status_manager_.saveCurStatus(); // save current staus

    // TODO
    status_manager_.clearAllBuffer();

    beforeRender();  
    startRender();
    status_manager_.resetStatus(); // reset
}



GENG_END