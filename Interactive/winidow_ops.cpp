//
// Created by zhanghong50 on 2022/1/13.
//

#include "winidow_ops.h"
#include "RenderModules/texture_mod.h"
#include "scene_tree_win.h"

namespace window{
    WindowOperation::WindowOperation():
    scene_win_(std::make_unique<SceneTreeWindow>()),
    log_win_(std::make_unique<LogWindow>()),
    menu_win_(std::make_unique<MenuWindow>()){
        title_ = "Hello!";
        win_height_ = 900;
        win_width_ = 1600;


        // start a glfw
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            return;

        // create a window
        GLFWwindow* window = glfwCreateWindow(win_width_, win_height_, "GEngine Window", NULL, NULL);
        if (window == NULL)
            return;
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable vsync

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL2_Init();

        // initialize the GEngine
        scene_manager_ = new gEngine::SceneManager(win_width_, win_height_);


        // Main loop
        while (!glfwWindowShouldClose(window)){

            glfwPollEvents();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL2_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            createBasicWindow();
            createFuncWindow();
            createResourceWindow();
            
            // Scene Tree
            menu_win_->showWindow(win_width_);
            scene_win_->showWindow(scene_manager_->getCurSceneTree()->getRootNode());
            log_win_->showWindow();
            // file_selection
            for(auto const & [name, fs_win]: file_selection_wins_){
                fs_win->showWindow();
                if(name == "TextureFiles"){
                    auto const & path = fs_win->getSelectedItem();
                    if(!path.empty())
                        scene_manager_->getResourceManager()->loadBundleTextureFromDir(path, gEngine::CubeMapTexture);
                }
                else if(name == "ModelFiles"){
                    auto const & path = fs_win->getSelectedItem();
                    if(!path.empty()){
                        scene_manager_->getCurSceneTree()->addChildren(path);
                    }
                }
            }

            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);

            // TODO
            // RenderService
            scene_manager_->startRenderService();

            // If you are using this code with non-legacy OpenGL header/contexts (which you should not, prefer using imgui_impl_opengl3.cpp!!),
            // you may need to backup/reset/restore other state, e.g. for current shader using the commented lines below.
            //GLint last_program;
            //glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
            //glUseProgram(0);
            ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
            //glUseProgram(last_program);
            glfwMakeContextCurrent(window);
            glfwSwapBuffers(window);
        }

        // Cleanup
        ImGui_ImplOpenGL2_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    WindowOperation::~WindowOperation() {
        delete scene_manager_;
    }



    void WindowOperation::createBasicWindow() {
        // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
//            static float f = 0.0f;
            const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 20), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2(340, 220), ImGuiCond_Always);
            static bool basic_win = true;
            ImGui::Begin("Welcome, AliceEngine!", &basic_win,  ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);                          // Create a window called "Hello, world!" and append into it.
            ImGui::Text("Welcome, AliceEngine!"); 
            ImGui::Checkbox("Objects", &primitives_window);  ImGui::SameLine(); 
            ImGui::Checkbox("SceneTree", &scene_win_->getWinStatus());  ImGui::SameLine(); 
            ImGui::Checkbox("Resource", &resource_window);  ImGui::SameLine(); 
            ImGui::Checkbox("Log", &log_win_->getWinStatus()); 
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
    }

    void WindowOperation::createFuncWindow() {
        // Show another simple window.
        if (primitives_window)
        {
            // set the parameter of the new window
            const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 950, main_viewport->WorkPos.y + 30), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(550, 220), ImGuiCond_Once);

            ImGui::Begin("Object", &primitives_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Primitives: ");


            // plane
            if (ImGui::Button("Insert Plane"))
            {
                scene_manager_->getCurSceneTree()->addChildren(gEngine::PREDECLARED_PLANE);
                num_plane += 1;
            }
            ImGui::SameLine();
            ImGui::Text("number of planes = %d", num_plane);

            // plane
            if (ImGui::Button("Insert Cube"))
            {
                scene_manager_->getCurSceneTree()->addChildren(gEngine::PREDECLARED_CUBE);
                num_cube_ += 1;
            }
            ImGui::SameLine();
            ImGui::Text("number of cube = %d", num_cube_);


            // plane
            if (ImGui::Button("Insert Sphere"))
            {
                scene_manager_->getCurSceneTree()->addChildren(gEngine::PREDECLARED_SPHERE);
                num_sphere_ += 1;
            }
            ImGui::SameLine();
            ImGui::Text("number of sphere = %d", num_sphere_);

            if (ImGui::Button("Insert Model"))
            {
                if(file_selection_wins_.find("ModelFiles") == file_selection_wins_.end()){
                    file_selection_wins_["ModelFiles"] = std::make_shared<FileSelectionWindow>("ModelFiles");
                }
                file_selection_wins_.at("ModelFiles")->openWindow();
            }
            ImGui::SameLine();
            ImGui::Text("number of model = %d", num_model_);

            // plane
            if (ImGui::Button("Insert HeightMap"))
            {
                scene_manager_->getCurSceneTree()->addChildren(gEngine::HEIGHT_MAP);
                num_height_map_ += 1;
            }
            ImGui::SameLine();
            ImGui::Text("number of height map = %d", num_height_map_);

            if (ImGui::Button("Exit"))
                primitives_window = false;
            ImGui::End();
        }
    }

    void WindowOperation::createSceneSettingChildWindow(){
        ImGui::BeginChild("Scene Setting", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); 
        ImGui::Text("Scene Settting: ");
        if(ImGui::TreeNode("Shadows")){
            static bool enable_shadow = false;
            static bool is_soft_shadow = true;
            ImGui::Checkbox("Enable Shadows",  & enable_shadow);
            ImGui::Checkbox("Enable Soft Shadows", & is_soft_shadow);
            scene_manager_->enableShadow(enable_shadow);
            scene_manager_->enableSoftShadow(is_soft_shadow);
            ImGui::TreePop();
        }

        ImGui::EndChild();
    }

    void WindowOperation::createResourceWindow() {
        if(resource_window){
            const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 460), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2(340, win_height_-460), ImGuiCond_Always);
            if (ImGui::Begin("Resource", &resource_window, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing))
            {
                std::string selected_obj = scene_win_->getSelectedItem();
                if(!selected_obj.empty()){
                    if(selected_obj == SceneTreeRootName){
                        createSceneSettingChildWindow();
                        ImGui::End();
                        return;
                    }

                    ImGui::BeginGroup();
                    ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
                    ImGui::Text("Object Name: %s", selected_obj.c_str());
                    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
                    {
                        if (ImGui::BeginTabItem("Attributes"))
                        {
                            if(scene_manager_->isCameraNode(selected_obj)){
                                gEngine::GVec3 pos = scene_manager_->getPosOfNode(selected_obj) * 100.0f;
                                ImGui::DragFloat3("Translation", &pos[0], 1.0f, -1000.0f, 1000.0f, "%.0f");
                                scene_manager_->setPosOfNode(selected_obj, pos/100.0f);
                                 // rotation
                                gEngine::GVec3 rot = scene_manager_->getRotOfNode(selected_obj);
                                ImGui::DragFloat3("Rotation", &rot[0], 0.01f, -360.0f, 360.0f, "%.00f", ImGuiSliderFlags_NoRoundToFormat);
                                scene_manager_->setRotOfNode(selected_obj, rot);
                            }
                            else if(scene_manager_->isLightNode(selected_obj)){
                                gEngine::LightType light_type = scene_manager_->getLightType(selected_obj);
                                switch (light_type) {
                                    case gEngine::POINT_LIGHT:{
                                        break; //TODO
                                    }
                                    case gEngine::DIRECTIONAL_LIGHT:{
                                        // rotation
                                        gEngine::GVec3 rot = scene_manager_->getRotOfNode(selected_obj);
                                        ImGui::DragFloat2("Direction", &rot[0], 1.0f, -360.0f, 360.0f, "%.0f");
                                        scene_manager_->setRotOfNode(selected_obj, rot);
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                            else if(scene_manager_->isObjectNode(selected_obj)){
                            //     // TODO
                                ImGui::Text("Transformation: ");
                                // translation
                                gEngine::GVec3 pos = scene_manager_->getPosOfNode(selected_obj) * 100.0f;
                                ImGui::DragFloat3("Translation", &pos[0], 1.0f, -400.0f, 400.f, "%.0f");
                                scene_manager_->setPosOfNode(selected_obj, pos/100.0f);
                                // rotation
                                gEngine::GVec3 rot = scene_manager_->getRotOfNode(selected_obj);
                                ImGui::DragFloat3("Rotation", &rot[0], 1.0f, -360.0f, 360.0f, "%.0f");
                                scene_manager_->setRotOfNode(selected_obj, rot);
                                // scale
                                static bool lock_label = true;
                                gEngine::GVec3 size = scene_manager_->getSizeOfNode(selected_obj) * 100.0f; 
                                if(!lock_label){
                                    ImGui::DragFloat3("Scale", &size[0], 1.0f, 12.5f, 2500.0f, "%.0f");
                                    scene_manager_->setSizeOfNode(selected_obj, size/100.0f);
                                }
                                else {
                                    ImGui::DragFloat("Scale", &size[0], 1.0f, 12.5f, 2500.0f, "%.0f");
                                    scene_manager_->setSizeOfNode(selected_obj, gEngine::GVec3(size[0]/100.0f));
                                }    
                                ImGui::SameLine();
                                if(ImGui::SmallButton("s^")){
                                    lock_label = !lock_label;
                                }
                            }

                            ImGui::EndTabItem();
                        }
                        if (ImGui::BeginTabItem("Textures")){
                            if(!selected_obj.empty()){
                                static std::string tex_selected = "ColorTexture0";
                                if(ImGui::BeginCombo("Color: ", tex_selected.c_str())){
                                    auto const & names = scene_manager_->getResourceManager()->getTexture2DNames();
                                    for (auto const & name : names)
                                    {
                                        const bool is_selected = (tex_selected == name);
                                        if (ImGui::Selectable(name.c_str(), is_selected))
                                        {
                                            tex_selected = name;
                                            scene_manager_->setColorTexOfNode(selected_obj, tex_selected);
                                        }
                                        if (is_selected)
                                            ImGui::SetItemDefaultFocus();
                                    }
                                    ImGui::EndCombo();
                                }

                                static std::string cube_t_selected = "None";
                                if(ImGui::BeginCombo("CubeMap: ", cube_t_selected.c_str())){
                                    auto const & names = scene_manager_->getResourceManager()->getTexture3DNames();
                                    for (auto const & name : names)
                                    {
                                        const bool is_selected = (cube_t_selected == name);
                                        if (ImGui::Selectable(name.c_str(), is_selected))
                                        {
                                            cube_t_selected = name;
                                            scene_manager_->setCubeMapOfNode(selected_obj, cube_t_selected);
                                        }
                                        if (is_selected)
                                            ImGui::SetItemDefaultFocus();
                                    }
                                    ImGui::EndCombo();
                                }
                                ImGui::SameLine();
                                if(ImGui::Button("add CubeMap")){
                                    if(file_selection_wins_.find("TextureFiles") == file_selection_wins_.end()){
                                        file_selection_wins_["TextureFiles"] = std::make_shared<FileSelectionWindow>("TextureFiles");
                                    }
                                    file_selection_wins_.at("TextureFiles")->openWindow();
                                }
                            }
                            ImGui::EndTabItem();
                        }
                        if (ImGui::BeginTabItem("Effects")){
                            if(!selected_obj.empty()){
                                // effects
                                auto effects = scene_manager_->getEffects();
                                for(auto const& effect : effects){
                                    if(ImGui::SmallButton(effect.c_str())){
                                        scene_manager_->setEffectOfNode(selected_obj, effect.c_str());
                                    }
                                }
                            }
                            ImGui::EndTabItem();
                        }
                        ImGui::EndTabBar();
                    }
                    ImGui::EndChild();
                    ImGui::EndGroup();
                }
            }
            ImGui::End();
        }
    }
}