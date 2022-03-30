//
// Created by HongZh on 2022/03/08, 13:52:59
//

#include "scene_tree_win.h"
#include "window_base.h"


namespace window{

SceneTreeWindow::SceneTreeWindow():
WindowBase(true, "SceneTree"){

}

SceneTreeWindow::~SceneTreeWindow(){

}

void SceneTreeWindow::traverseSceneTree(std::shared_ptr<gEngine::SceneNode> node, uint32_t level){
    if(node){
        std::string prefix(level, ' ');
        ImGui::Text("%s%s", prefix.c_str(), " |_"); ImGui::SameLine();
        if(ImGui::Selectable(node->getNodeName().c_str())){
            selected_item_ = node->getNodeName();
        }
        for(auto child_node: node->getChildrenNode()){
            traverseSceneTree(child_node, level+1);
        }

    }
}

const std::string & SceneTreeWindow::getSelectedItem(){
    return selected_item_;
}

// TODO
void SceneTreeWindow::showWindow(...){

}

void SceneTreeWindow::showWindow(std::shared_ptr<gEngine::SceneNode> node){
    if(is_open_)
    {
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 240), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(340, 220), ImGuiCond_Always);
        ImGui::Begin("SceneManager", &is_open_, ImGuiWindowFlags_NoResize);   
        traverseSceneTree(node);
        ImGui::End();
    }
}

}