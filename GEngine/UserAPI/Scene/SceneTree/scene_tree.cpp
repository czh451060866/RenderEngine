//
// Created by zhanghong50 on 2022/1/19.
//

#include "scene_tree.h"
#include "model_node.h"
#include "primitive_node.h"
#include "light_node.h"
#include "camera_node.h"
#include "Resources/resource_manager.h"
#include "RenderService/render_server.h"

GENG_BEGIN

SceneTree::SceneTree():
scene_setting_(std::make_shared<SceneSetting>()),
root_node_(std::make_shared<SceneNode>()),
cur_activated_node_(root_node_){
    root_node_->setNodeName("Scene Root");
}

SceneTree::~SceneTree(){

}

void SceneTree::setRenderServer(std::shared_ptr<RenderServer> render_server){
    render_server_ = render_server;
}
void SceneTree::setResourceManager(std::shared_ptr<ResourceManager> resource_manager){
    resource_manager_ = resource_manager;
}

// insert model
void SceneTree::addChildren(const std::string & path){
    // Resource Manager
    // Scene Tree
    std::shared_ptr<SceneNode> node;

    node = std::make_shared<ModelNode>();
    node->setNodeName("Model" + std::to_string(model_id_++));
    num_of_model_++;

    cur_activated_node_->addChild(node);

    // load model 
    resource_manager_->insertModel(node->getNodeName(), path);

    // camera
    node->setCamera(default_camera_);

    // lighting 
    node->setLighting(default_lighting_);

    // effect
    node->setEffect(default_effect_);

    // process the data
    render_server_->prepareRenderNode(node);

    // add to map
    all_object_node_[node->getNodeName()] = node;
    all_nodes_[node->getNodeName()] = node;
}

void SceneTree::addChildren(const MeshType & type) {

    // Resource Manager
    // Scene Tree
    std::shared_ptr<SceneNode> node;
    switch (type) {
        case PREDECLARED_PLANE: {
            node = std::make_shared<PrimitiveNode>(type);
            node->setNodeName("Plane" + std::to_string(plane_id_++));
            num_of_plane_++;
            break;
        }
        case PREDECLARED_CUBE: {
            node = std::make_shared<PrimitiveNode>(type);
            node->setNodeName("Cube" + std::to_string(cube_id_++));
            num_of_cube_++;
            break;
        }
        case PREDECLARED_SPHERE:{
            node = std::make_shared<PrimitiveNode>(type);
            node->setNodeName("Sphere" + std::to_string(sphere_id_++));
            num_of_sphere_++;
            break;
        }
        case HEIGHT_MAP: {
            node = std::make_shared<PrimitiveNode>(type);
            node->setNodeName("HeightMap" + std::to_string(height_map_id_++));
            num_of_height_map++;
            break;
        }
        default:
            break;
    }
    cur_activated_node_->addChild(node);

    // mesh
    resource_manager_->insertMesh(node->getNodeName(), type);

    // camera
    node->setCamera(default_camera_);

    // lighting 
    node->setLighting(default_lighting_);

    // effect
    node->setEffect(default_effect_);

    // process the data
    render_server_->prepareRenderNode(node);

    // add to map
    all_object_node_[node->getNodeName()] = node;
    all_nodes_[node->getNodeName()] = node;
}

void SceneTree::addChildren(const LightType & type) {

    // Scene Node
    std::shared_ptr<SceneNode> node;
    switch (type) {
        case POINT_LIGHT: {
            node = std::make_shared<LightNode>(type);
            node->setNodeName( "PointLight" + std::to_string(point_light_id_++));
            num_of_light_++;

            // mesh 
            resource_manager_->insertMesh(node->getNodeName(), PREDECLARED_CUBE);
            break;
        }
        case DIRECTIONAL_LIGHT: {
            node = std::make_shared<LightNode>(type);
            node->setNodeName("DirectedLight" + std::to_string(directed_light_id_++));
            num_of_light_++;
            break;
        }
        default:
            break;
    } 
    cur_activated_node_->addChild(node);

    // create the light 
    resource_manager_->insertLight(node->getNodeName(), type);

    // camera
    node->setCamera(default_camera_);

    // lighting 
    node->setLighting(default_lighting_);

    // effect
    node->setEffect(default_effect_);

    // process the data
    render_server_->prepareRenderNode(node);

    // add to map
    all_light_node_[node->getNodeName()] = node;
    all_nodes_[node->getNodeName()] = node;
}


bool SceneTree::isCameraNode(const std::string & node_name){
    if(all_camera_node_.find(node_name) != all_camera_node_.end()){
        return true;
    }
    return false;
}

bool SceneTree::isLightNode(const std::string & node_name){
    if(all_light_node_.find(node_name) != all_light_node_.end()){
        return true;
    }
    return false;
}

bool SceneTree::isObjectNode(const std::string & node_name){
    if(all_object_node_.find(node_name) != all_object_node_.end()){
        return true;
    }
    return false;
}

void SceneTree::addChildren(const CameraType & type) {

    // Scene Node
    std::shared_ptr<SceneNode> node;
    switch (type) {
        case PINHOLE_CAMERA: {
            node = std::make_shared<CameraNode>(type);
            node->setNodeName( "PinHoleCamera" + std::to_string(camera_id_++));
            num_of_camera_++;
            break;
        }
        default:
            break;
    }
    cur_activated_node_->addChild(node);

    resource_manager_->insertCamera(node->getNodeName(), type);

    // camera
    node->setCamera(default_camera_);

    // lighting 
    node->setLighting(default_lighting_);

    // effect
    node->setEffect(default_effect_);

    // add to map
    all_camera_node_[node->getNodeName()] = node;
    all_nodes_[node->getNodeName()] = node;
}

const std::map<std::string, std::shared_ptr<SceneNode>> & SceneTree::getAllCameraSceneNode() {
    return all_camera_node_;
}


const std::map<std::string, std::shared_ptr<SceneNode>> & SceneTree::getAllLightSceneNode() {
    return all_light_node_;
}

const std::map<std::string, std::shared_ptr<SceneNode>> & SceneTree::getAllObjectSceneNode() {
    return all_object_node_;
}

const std::map<std::string, std::shared_ptr<SceneNode>> & SceneTree::getAllSceneNode(){
    return all_nodes_;
}

std::shared_ptr<SceneNode> SceneTree::getRootNode() {
    return root_node_;
}

std::shared_ptr<SceneSetting> SceneTree::getSceneSetting(){
    return scene_setting_;
}

const uint32_t & SceneTree::getNumOfObject() {
    num_of_object_ = num_of_plane_ + num_of_cube_ + num_of_sphere_;
    return num_of_object_;
}

const uint32_t & SceneTree::getNumOfCamera() {
    return num_of_camera_;
}

const uint32_t & SceneTree::getNumOfLight() {
    return num_of_light_;
}

const uint32_t & SceneTree::getNumOfPlane() {
    return num_of_plane_;
}

const uint32_t & SceneTree::getNumOfCube() {
    return num_of_cube_;
}

GENG_END