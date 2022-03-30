//
// Created by HongZh on 2022/03/08, 13:47:48
//

#ifndef MYENGINE_SCENE_TREE_WIN_H
#define MYENGINE_SCENE_TREE_WIN_H

#include "window_base.h"
#include "UserAPI/Scene/scene_manager.h"

namespace window
{

class SceneTreeWindow : public WindowBase{
private:
    // function pointer
    std::string selected_item_ = SceneTreeRootName;
public:
    SceneTreeWindow();
    ~SceneTreeWindow();

    const std::string & getSelectedItem();
    void showWindow(...) override;
    void showWindow(std::shared_ptr<gEngine::SceneNode> node);
    void traverseSceneTree(std::shared_ptr<gEngine::SceneNode> node, uint32_t level=0);
};

}

#endif //MYENGINE_SCENE_TREE_WIN_H