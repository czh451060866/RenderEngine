//
// Created by zhanghong50 on 2022/1/31.
//

#ifndef MYENGINE_RENDER_INTEGRATOR_H
#define MYENGINE_RENDER_INTEGRATOR_H

#include "data_predeclared.h"
#include "render_mesh.h"
#include "render_node.h"
#include "render_system.h"
#include "render_parameter.h"
#include "RenderQueue/render_queue.h"
#include "RenderBuffer/data_pool.h"
#include "RenderBuffer/shader_pool.h"
#include "RenderBuffer/texture_pool.h"

GENG_BEGIN

class RenderIntegrator {
public:
    RenderIntegrator();
    ~RenderIntegrator();

    void processRenderNode(std::shared_ptr<RenderNode> node);
    void buildRenderQueue(RenderQueue & queue); // push into the render queue
    void updateRenderData(std::shared_ptr<RenderNode> render_node, std::shared_ptr<RenderData> render_data); // update render data

    void setRenderSystem(std::shared_ptr<RenderSystem> render_system);
private:
    // TODO : need to try other structures instead of vector
    std::vector<std::shared_ptr<RenderMesh>> mesh_list_;
    std::vector<std::shared_ptr<RenderNode>> node_list_;  // TODO
    std::vector<std::shared_ptr<RenderData>> data_list_; // TODO
    std::unordered_map<std::string, std::shared_ptr<RenderParam>> param_list_; // TODO

    std::shared_ptr<RenderSystem> render_system_ptr_;
};

GENG_END


#endif //MYENGINE_RENDER_INTEGRATOR_H
