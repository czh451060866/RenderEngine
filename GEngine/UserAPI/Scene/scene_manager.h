//
// Created by Hong on 2022/2/17.
//

#ifndef MYENGINE_SCENE_MANAGER_H
#define MYENGINE_SCENE_MANAGER_H

#include "SceneTree/scene_tree.h"
#include "FileSystem/file_handler.h"

GENG_BEGIN

class SceneManager {
public:
    SceneManager(u_int32_t w, u_int32_t h);
    ~SceneManager();

    uint32_t addScene();
    SceneTree * getCurSceneTree();
    std::shared_ptr<ResourceManager> getResourceManager();
    void startRenderService();   

    void enableShadow(const bool & flag);
    void enableSoftShadow(const bool & flag);
    void setPosOfNode(const std::string & node_name, const GVec3 & pos);
    void setSizeOfNode(const std::string & node_name, const GVec3 & size);
    void setRotOfNode(const std::string & node_name, const GVec3 & rot);
    void setColorOfNode(const std::string & node_name, const GVec3 & color);
    void setEffectOfNode(const std::string & node_name, const std::string & effect_name);
    void setColorTexOfNode(const std::string & node_name, const std::string & tex_name);
    void setCubeMapOfNode(const std::string &node_name, const std::string &tex_name);

    bool isCameraNode(const std::string & node_name);
    bool isLightNode(const std::string & node_name);
    bool isObjectNode(const std::string & node_name);
    const bool & isEnableShadow();
    const bool & isEnableSoftShadow();
    const std::vector<std::string> & getEffects();
    const GVec3 & getSizeOfNode(const std::string & name);
    const GVec3 & getPosOfNode(const std::string & name);
    const GVec3 & getRotOfNode(const std::string & name);
    const GVec3 & getColorOfNode(const std::string & name);
    const LightType getLightType(const std::string & name);
    const CameraType getCameraType(const std::string & name);
    const std::string & getColorTexOfNode(const std::string & name);
    const std::string & getCubeMapOfNode(const std::string &name);

private:
    std::vector<SceneTree *> scene_tree_;
    std::shared_ptr<ResourceManager> resource_manager_;   // TODO
    std::shared_ptr<RenderServer>  render_server_; // TODO 
    size_t cur_activated_scene_; 
};

GENG_END

#endif //MYENGINE_SCENE_MANAGER_H
