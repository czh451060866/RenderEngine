//
// Created by HongZh on 2022/03/08, 11:20:57
//

#include "file_selection_win.h"

namespace window{

FileSelectionWindow::FileSelectionWindow():
WindowBase(false, "Files"), 
selected_item_(""),
cur_path_(std::filesystem::current_path()) {

}

FileSelectionWindow::FileSelectionWindow(std::string name):
WindowBase(false, name),
cur_path_(std::filesystem::current_path()),
selected_item_("") {

}

FileSelectionWindow::~FileSelectionWindow(){

}


bool FileSelectionWindow::loadCurrentFiles(std::string & path){
    if(std::filesystem::is_directory(path)){
        for(const auto & entry: std::filesystem::directory_iterator(path)){
            std::string fpath = entry.path();
            std::string fname = fpath.substr(fpath.find_last_of("/")+1);
            if(ImGui::Selectable(fname.c_str(), path == fpath)) {
                path = fpath;
            }
        }
        return false;
    }
    return true;
}


void FileSelectionWindow::showWindow(...){
    std::lock_guard<std::mutex> locker(mtx_);

    if(is_open_){
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 460, main_viewport->WorkPos.y + 260), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(600, 500), ImGuiCond_Once);
        ImGui::Begin(window_name_.c_str(), &is_open_); 
        bool is_file = loadCurrentFiles(cur_path_);
        ImGui::Selectable(cur_path_.c_str(), true);
        if(is_file && ImGui::Button("Load")){
            is_open_ = false;
            selected_item_ = cur_path_;
        }
        else if(!is_file && ImGui::Button("Open")){
            is_open_ = false;
            selected_item_ = cur_path_;
        }
        if(ImGui::Button("Backward")){
            std::string temp = cur_path_.substr(0, cur_path_.find_last_of("/"));
            if(!temp.empty())
                cur_path_ = temp;
        }
        if (ImGui::Button("Exit")){
            is_open_ = false;
        }
        ImGui::End();
    }
}

const std::string FileSelectionWindow::getSelectedItem(){
    std::lock_guard<std::mutex> locker(mtx_);
    const std::string temp = selected_item_;
    selected_item_.clear();
    return std::move(temp);
}

}