//
// Created by zhanghong50 on 2022/2/14.
//

#ifndef MYENGINE_RENDER_SYSTEM_H
#define MYENGINE_RENDER_SYSTEM_H

#include "data_predeclared.h"
#include "render_node.h"
#include "render_parameter.h"

GENG_BEGIN

// base class for resource manager that has access to all kinds of systems, like: light, camera, etc.
// CPU buffer
class RenderSystem {
public:
    RenderSystem();
    virtual ~RenderSystem();
    virtual std::shared_ptr<RenderMesh> getRenderMesh(std::shared_ptr<RenderNode> & node) = 0;
    virtual void getRenderParam(std::shared_ptr<RenderNode> & node, std::shared_ptr<RenderParam> & param) = 0;
protected:
    std::unordered_map<std::string, std::shared_ptr<RenderParam>> render_params_;   // CPU buffers for Uniforms
};

GENG_END


#endif //MYENGINE_RENDER_SYSTEM_H
