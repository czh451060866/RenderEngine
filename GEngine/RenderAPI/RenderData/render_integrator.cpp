//
// Created by zhanghong50 on 2022/1/31.
//

#include "render_integrator.h"
#include "RenderAPI/RenderQueue/render_data.h"
#include "general_include.h"


GENG_BEGIN

RenderIntegrator::RenderIntegrator(){
}

RenderIntegrator::~RenderIntegrator() {

}

// void RenderIntegrator::setRenderSystem(std::shared_ptr<RenderSystem> render_system){
//     render_system_ = render_system;
// }

// TODO
// to create GPU buffer
void RenderIntegrator::processRenderNode(std::shared_ptr<RenderNode> node) {
    if(node->getMeshType() == NONE_MESH || !render_system_ptr_){
        return;
    }

    // TODO
    // initialize the render data
    std::shared_ptr<RenderData> render_data = std::make_shared<RenderData>();

    // mesh
    const std::string & node_name = node->getNodeName();
    std::shared_ptr<RenderMesh> mesh = render_system_ptr_->getRenderMesh(node);
    if(!mesh){
        return;
    }

    DataPool & data_pool_ = DataPool::getInstance();
    auto data_modules = data_pool_.loadData(mesh);
    render_data->setDataModule(data_modules);

    // draw
    std::shared_ptr<DrawModule> draw_mod = DrawModule::getInstance(mesh->getNumOfFace());
    render_data->setDrawCall(draw_mod);

    // save the render_data
    mesh_list_.push_back(mesh);
    data_list_.push_back(render_data);
    node_list_.push_back(node);

}

void RenderIntegrator::setRenderSystem(std::shared_ptr<RenderSystem> render_system){
    render_system_ptr_ = render_system;
}


// update the render data
void RenderIntegrator::updateRenderData(std::shared_ptr<RenderNode> render_node, std::shared_ptr<RenderData> render_data) {
    if(render_system_ptr_){
        // shader
        const std::string & effect_name = render_node->getEffectName();
        ShaderPool & shader_pool = ShaderPool::getInstance();
        std::shared_ptr<ShaderModule> shader = shader_pool.getShaderModule(effect_name);
        render_data->setShaderProgram(shader);

        // params
        const std::string & node_name = render_node->getNodeName();
        if(param_list_.find(node_name) != param_list_.end()){
            std::shared_ptr<RenderParam> & param = param_list_[node_name];
            render_system_ptr_->getRenderParam(render_node, param);
        }
        else{
             std::shared_ptr<RenderParam> param = std::make_shared<RenderParam>();
            render_system_ptr_->getRenderParam(render_node, param); 
            if(param){
                param_list_[node_name] = param;
            }
        }
        render_data->setRenderParam(param_list_.at(node_name));
    }
}


void RenderIntegrator::buildRenderQueue(RenderQueue &queue) {
    for(size_t i = 0 ; i<data_list_.size(); i++){
        updateRenderData(node_list_[i], data_list_[i]);
        queue.pushQueue(data_list_[i]);
    }
}


GENG_END
