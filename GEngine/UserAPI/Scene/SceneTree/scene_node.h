//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_SCENE_NODE_H
#define MYENGINE_SCENE_NODE_H

#include "Scene/scene_predeclared.h"
#include "RenderAPI/RenderData/render_node.h"

GENG_BEGIN

class SceneNode: public RenderNode{
public:
    SceneNode();
    virtual ~SceneNode();

    // functions
    void addChild(const std::shared_ptr<SceneNode> & node);
    std::vector<std::shared_ptr<SceneNode>> & getChildrenNode();
    const NodeType & getNodeType();

protected:
    NodeType node_type_;
    std::vector<std::shared_ptr<SceneNode>> children_node_;  // children
};

GENG_END


#endif //MYENGINE_SCENE_NODE_H
