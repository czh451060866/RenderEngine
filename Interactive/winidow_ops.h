//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_WINIDOW_OPS_H
#define MYENGINE_WINIDOW_OPS_H


#include <memory>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include "GLFW/glfw3.h"

#include "window_predeclared.h"
#include "UserAPI/Scene/scene_manager.h"

#include "file_selection_win.h"
#include "scene_tree_win.h"
#include "log_win.h"
#include "menu_win.h"

namespace window {

    class WindowOperation {
    private:

        std::map<std::string, std::shared_ptr<FileSelectionWindow>> file_selection_wins_;
        std::unique_ptr<SceneTreeWindow> scene_win_;
        std::unique_ptr<LogWindow> log_win_;
        std::unique_ptr<MenuWindow> menu_win_;

        std::string title_;
        uint32_t win_width_;
        uint32_t win_height_;

        // scene manager
        gEngine::SceneManager * scene_manager_;

        // subwindow params
        // TODO: subwindow Class
        bool primitives_window = true;
        bool resource_window = true;
        uint32_t num_plane = 0;
        uint32_t num_cube_ = 0;
        uint32_t num_sphere_ = 0;
        uint32_t num_height_map_ = 0;
        uint32_t num_model_ = 0;
        ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

    public:
        WindowOperation();
        ~WindowOperation();

        void createBasicWindow();
        void createFuncWindow();
        void createResourceWindow();
        void createSceneSettingChildWindow();
    };
}


#endif //MYENGINE_WINIDOW_OPS_H
