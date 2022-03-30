//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_SCENE_TREE_H
#define MYENGINE_SCENE_TREE_H

#include "scene_node.h"
#include "FunctionAPI/Resources/resource_manager.h"
#include "RenderAPI/RenderService/render_server.h"
#include "Scene/SceneSetting/scene_setting.h"

GENG_BEGIN

class SceneTree {
public:
    SceneTree();
    ~SceneTree();

    void setRenderServer(std::shared_ptr<RenderServer> render_server);
    void setResourceManager(std::shared_ptr<ResourceManager> resource_manager);

    std::shared_ptr<SceneSetting> getSceneSetting();
    std::shared_ptr<SceneNode> getRootNode();
    const std::map<std::string, std::shared_ptr<SceneNode> > & getAllCameraSceneNode();   // get printer from tree map
    const std::map<std::string, std::shared_ptr<SceneNode> > & getAllLightSceneNode();   // get printer from tree map
    const std::map<std::string, std::shared_ptr<SceneNode> > & getAllObjectSceneNode();   // get printer from tree map
    const std::map<std::string, std::shared_ptr<SceneNode> > & getAllSceneNode(); 

    bool isCameraNode(const std::string & node_name);
    bool isLightNode(const std::string & node_name);
    bool isObjectNode(const std::string & node_name);
    void addChildren(const MeshType & type);
    void addChildren(const CameraType & type);
    void addChildren(const LightType & type);
    void addChildren(const std::string & path);
//    void deleteChild(); // TODO

    // check the number of nodes
    const uint32_t & getNumOfObject();
    const uint32_t & getNumOfPlane();
    const uint32_t & getNumOfCube();
    const uint32_t & getNumOfCamera();
    const uint32_t & getNumOfLight();

private:
    //TODO 
    std::shared_ptr<SceneSetting> scene_setting_;
    std::shared_ptr<RenderServer> render_server_;
    std::shared_ptr<ResourceManager> resource_manager_;

    std::shared_ptr<SceneNode> root_node_;
    std::shared_ptr<SceneNode> cur_activated_node_;
    std::map<std::string, std::shared_ptr<SceneNode> > all_camera_node_;
    std::map<std::string, std::shared_ptr<SceneNode> > all_light_node_;
    std::map<std::string, std::shared_ptr<SceneNode> > all_object_node_;
    std::map<std::string, std::shared_ptr<SceneNode> > all_nodes_;

    uint32_t num_of_object_ = 0;
    uint32_t num_of_plane_ = 0;
    uint32_t num_of_cube_ = 0;
    uint32_t num_of_model_ = 0;
    uint32_t num_of_sphere_ = 0;
    uint32_t num_of_height_map = 0;
    uint32_t num_of_light_ = 0;
    uint32_t num_of_camera_ = 0;

    uint32_t plane_id_ = 0;
    uint32_t model_id_ = 0;
    uint32_t cube_id_ = 0;
    uint32_t sphere_id_ = 0;
    uint32_t height_map_id_ = 0;
    uint32_t light_id_ = 0;
    uint32_t camera_id_ = 0;
    uint32_t point_light_id_ = 0;
    uint32_t directed_light_id_ = 0;

    std::string default_lighting_ = "DirectedLight0"; // default
    std::string default_camera_ = "PinHoleCamera0";
    std::string default_effect_ = "PureColor";

};

GENG_END

#endif //MYENGINE_SCENE_TREE_H
