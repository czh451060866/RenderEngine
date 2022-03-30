//
// Created by HongZh on 2022/03/10, 11:46:05
//

#include "log_win.h"
#include "RenderLog/render_log.h"


namespace window {

LogWindow::LogWindow():
WindowBase(true, "Log Window"),
num_of_log_(0){

}

LogWindow::~LogWindow(){
    clear();
}

void LogWindow::clear(){
    for(auto const & buf : buffers_){
        if(buf)
            free(buf);
    }
    buffers_.clear();
}

// TODO
void LogWindow::addLog(){
    if(buffers_.size()>= MAX_LENGTH_OF_BUFFER){
        clear();
    }
    gEngine::RenderLog & render_log = gEngine::RenderLog::getInstance();
    std::vector<char*> & logs = render_log.getLogs();
    if(!logs.empty()){
        buffers_.insert(buffers_.end(), logs.begin(), logs.end());
        logs.clear();
    }
}

void LogWindow::showWindow(...){
    if(is_open_){
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 1100, main_viewport->WorkPos.y + 500), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(340, 360), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.3);
        ImGui::Begin("Log Window", &is_open_, ImGuiWindowFlags_NoDecoration  | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav);  
        ImGui::Text("Log Info: ");
        ImGui::Separator();
        ImGui::SetNextWindowBgAlpha(0.3);
        ImGui::BeginChild("log info", ImVec2(320, 320), true);
        addLog();
        for(auto & log : buffers_){
            ImGui::TextColored(ImVec4(1,1,0,1),"%s", log);
        }
        ImGui::EndChild();
        ImGui::End();
    }
}

}