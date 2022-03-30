//
// Created by HongZh on 2022/03/23, 18:04:42
//

#include "selected_combo_plugin.h"

namespace window{

SelectedComboPlugin::SelectedComboPlugin(const std::string & name):
PluginBase(name){

}

SelectedComboPlugin::~SelectedComboPlugin(){

}

void SelectedComboPlugin::showPlugin(const std::vector<std::string> & names){
    if(ImGui::BeginCombo(plugin_name_.c_str(), selected_item_.c_str())){
        for (auto const & name : names){
            const bool is_selected = (selected_item_ == name);
            if (ImGui::Selectable(name.c_str(), is_selected))
            {
                selected_item_ = name;
                doActionFunc(plugin_name_, selected_item_);
            }
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
}


}