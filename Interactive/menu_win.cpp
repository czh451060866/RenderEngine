//
// Created by HongZh on 2022/03/24, 23:17:30
//

#include "menu_win.h"

namespace window {

MenuWindow::MenuWindow(){

}

MenuWindow::~MenuWindow(){

}

void MenuWindow::showWindow(...){
    va_list args;
    uint32_t width = va_arg(args, uint32_t);
    va_end(args);
    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(width, 20), ImGuiCond_Always);
    ImGui::Begin("Menu Window", &is_open_, ImGuiWindowFlags_MenuBar| ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize|ImGuiWindowFlags_NoDecoration|ImGuiWindowFlags_NoNav);
    if (ImGui::BeginMenuBar()){
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { 
                /* Do stuff */ 
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   {
                /* Do stuff */ 
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Mesh"))
        {
            if (ImGui::MenuItem("Load Mesh From Textures..", "Ctrl+P")) { 
                /* Do stuff */ 
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Textures"))
        {
            if (ImGui::MenuItem("Load..", "Ctrl+W")) { 
                /* Do stuff */ 
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Shaders"))
        {
            if (ImGui::MenuItem("Load..", "Ctrl+A")) { 
                /* Do stuff */ 
            }
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
    ImGui::End();
}

}