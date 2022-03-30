//
// Created by Hong on 2022/2/17.
//

#include "scene_manager.h"

GENG_BEGIN

SceneManager::SceneManager(u_int32_t w, u_int32_t h) {
    cur_activated_scene_ = -1;
    //TODO
    resource_manager_ = std::make_shared<ResourceManager>();
    resource_manager_->setWindowSize(w, h);
    
    render_server_ = std::make_shared<RenderServer>(resource_manager_);

    addScene();

}

SceneManager::~SceneManager() {
    // scene tree
    for(auto & tree: scene_tree_){
        delete tree;
    }

}

bool SceneManager::isCameraNode(const std::string &node_name){
    return scene_tree_[cur_activated_scene_]->isCameraNode(node_name);
}

bool SceneManager::isLightNode(const std::string &node_name){
    return scene_tree_[cur_activated_scene_]->isLightNode(node_name);
}

bool SceneManager::isObjectNode(const std::string &node_name){
    return scene_tree_[cur_activated_scene_]->isObjectNode(node_name);
}

const bool & SceneManager::isEnableShadow(){
    return scene_tree_[cur_activated_scene_]->getSceneSetting()->isEnableShadow();
}

const bool & SceneManager::isEnableSoftShadow(){
    return scene_tree_[cur_activated_scene_]->getSceneSetting()->isEnableSoftShadow();
}

const std::vector<std::string> & SceneManager::getEffects(){
    return resource_manager_->getEffectNames();
}

void SceneManager::enableShadow(const bool & flag){
    scene_tree_[cur_activated_scene_]->getSceneSetting()->isEnableShadow();
}

void SceneManager::enableSoftShadow(const bool & flag){
    scene_tree_[cur_activated_scene_]->getSceneSetting()->isEnableSoftShadow();
}


void SceneManager::setSizeOfNode(const std::string & node_name, const GVec3 & size){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    if(attrib)
        attrib->setScale(size);
}

void SceneManager::setRotOfNode(const std::string & node_name, const GVec3 & rot){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    attrib->setRotation(rot);
}


void SceneManager::setColorOfNode(const std::string & node_name, const GVec3 & color){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    attrib->setObjectColor(color);
}

void SceneManager::setEffectOfNode(const std::string & node_name, const std::string & effect_name){
    auto obj = getCurSceneTree()->getAllSceneNode();
    obj[node_name]->setEffect(effect_name);
}

void SceneManager::setColorTexOfNode(const std::string &node_name, const std::string &tex_name){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    if(attrib)
        attrib->setColorTexture(tex_name);
}

void SceneManager::setCubeMapOfNode(const std::string &node_name, const std::string &tex_name){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    if(attrib)
        attrib->setCubeTexture(tex_name);
}

void SceneManager::setPosOfNode(const std::string & node_name, const GVec3 & pos){
    auto attrib = resource_manager_->queryObjectAttribute(node_name);
    if(attrib)
        attrib->setTranslation(pos);
}

const GVec3 & SceneManager::getPosOfNode(const std::string & name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getObjectPosition();
}
const GVec3 & SceneManager::getRotOfNode(const std::string & name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getObjectRotation();
}

const GVec3 & SceneManager::getColorOfNode(const std::string & name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getObjectColor();
}

const LightType SceneManager::getLightType(const std::string &name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    if(attrib->isAttributeActivated(ILLUMINOUS_ATTRIB)){
        return attrib->getLightType();
    }
    return NONE_LIGHT;
}

const CameraType SceneManager::getCameraType(const std::string &name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    if(attrib->isAttributeActivated(CAMERA_ATTRIB)){
        return attrib->getCameraType();
    }
    return NONE_CAMERA;
}

const std::string & SceneManager::getColorTexOfNode(const std::string &name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getColorTexture();
}

const std::string & SceneManager::getCubeMapOfNode(const std::string &name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getCubeMap();
}

const GVec3 & SceneManager::getSizeOfNode(const std::string & name){
    auto attrib = resource_manager_->queryObjectAttribute(name);
    return attrib->getObjectScale();
}

std::shared_ptr<ResourceManager> SceneManager::getResourceManager(){
    return resource_manager_;
}

SceneTree * SceneManager::getCurSceneTree(){
    if(cur_activated_scene_>= 0 && cur_activated_scene_ < scene_tree_.size()){
        return scene_tree_[cur_activated_scene_];
    }
    return nullptr;
}

void SceneManager::startRenderService(){
    render_server_->startRenderService();
}

uint32_t SceneManager::addScene() {
    SceneTree* scene_tree = new SceneTree();
    scene_tree->setRenderServer(render_server_);
    scene_tree->setResourceManager(resource_manager_);
    // default
    scene_tree->addChildren(gEngine::DIRECTIONAL_LIGHT);
    scene_tree->addChildren(gEngine::PINHOLE_CAMERA);
    setPosOfNode("PinHoleCamera0", GVec3(0.0f, 0.0f, 10.0f));
    setRotOfNode("DirectedLight0", GVec3(120.0f, 0.0f, 0.0f));
    scene_tree_.emplace_back(scene_tree);
    cur_activated_scene_ += 1;
    return cur_activated_scene_;
}


GENG_END
