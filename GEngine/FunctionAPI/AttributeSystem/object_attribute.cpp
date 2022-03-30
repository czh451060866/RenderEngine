//
// Created by HongZh on 2022/03/19, 19:20:23
//

#include "object_attribute.h"

GENG_BEGIN

ObjectAttribute::ObjectAttribute(){

}

ObjectAttribute::~ObjectAttribute(){

}

void ObjectAttribute::addAttribute(const AttribInfo & attrib_info){
    // TODO
    // geometry attrib
    switch (attrib_info.mesh_type_) {
        case PREDECLARED_CUBE:
        case PREDECLARED_SPHERE:
        case PREDECLARED_PLANE:
        case IMPORTED_MODEL:{
            geometry_attrib_ = std::make_shared<GeometryBase>(attrib_info.mesh_type_);
            break;
        }
        default:
            is_activated_[GEOMETRY_ATTRIB] = false; 
            is_updated_[GEOMETRY_ATTRIB] = false; 
            break;
    }

    // CameraAttribute
    switch (attrib_info.camera_type_) {
        case PINHOLE_CAMERA:{
            camera_attrib_ = std::make_shared<CameraBase>();
            break;
        }
        default:
            is_activated_[CAMERA_ATTRIB] = false; 
            is_updated_[CAMERA_ATTRIB] = false; 
            break;
    }

    // illuminous attrib
    switch (attrib_info.light_type_) {
        case POINT_LIGHT:{
            illuminious_attrib_ = std::make_shared<PointLight>();
            break;
        }
        case DIRECTIONAL_LIGHT:{
            illuminious_attrib_ = std::make_shared<DirectionalLight>();
            break;
        }
        default:
            is_activated_[ILLUMINOUS_ATTRIB] = false; 
            is_updated_[ILLUMINOUS_ATTRIB] = false; 
            break;
    }

    // dynamics attrib
    // TODO
    switch (attrib_info.dynam_type_) {
        case RIGID_DYNAMICS:{
            dynamics_attrib_ = std::make_shared<TransformerBase>();
            break;
        }
        default:
            is_activated_[DYNAMICS_ATTRIB] = false; 
            is_updated_[DYNAMICS_ATTRIB] = false; 
            break;
    }

    // appearance attrib
    switch (attrib_info.appearance_type){
        case TEXTURE_APPEARANCE:{
            appearance_attrib_ = std::make_shared<TextureBase>();
            break;
        }
        default:
            is_activated_[APPEARANCEC_ATTRIB] = false; 
            is_updated_[APPEARANCEC_ATTRIB] = false; 
            break;
    }

}

const GVec3 & ObjectAttribute::getObjectPosition(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getTranslation();
}

const GVec3 & ObjectAttribute::getObjectScale(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getScale();
}

const GVec3 & ObjectAttribute::getObjectRotation(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getRotation();
}

const GVec3 & ObjectAttribute::getObjectFaceTo(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getFaceTo();
}

const GVec3 & ObjectAttribute::getObjectHeadUp(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getHeadUp();
}

const GVec3 & ObjectAttribute::getObjectRightSide(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getRightSide();
}

const GVec3 & ObjectAttribute::getObjectColor(){
    std::lock_guard<std::mutex> lock(mtx_);
    return appearance_attrib_->getObjectColor();
}

const std::string & ObjectAttribute::getColorTexture(){
    std::lock_guard<std::mutex> lock(mtx_);
    return appearance_attrib_->getColorTexture();
}

const std::string & ObjectAttribute::getCubeMap(){
    std::lock_guard<std::mutex> lock(mtx_);
    return appearance_attrib_->getCubeMapTexture();
}

const std::string & ObjectAttribute::getNormalTexture(){
    std::lock_guard<std::mutex> lock(mtx_);
    return appearance_attrib_->getNormalTexture();
}

const LightType & ObjectAttribute::getLightType(){
    std::lock_guard<std::mutex> lock(mtx_);
    return illuminious_attrib_->getType();
}

const CameraType & ObjectAttribute::getCameraType(){
    std::lock_guard<std::mutex> lock(mtx_);
    return camera_attrib_->getCameraType();
}

const GMat4 & ObjectAttribute::getCameraProjMat(){
    std::lock_guard<std::mutex> lock(mtx_);
    return camera_attrib_->getPerspectiveMat();
}
const GMat4 & ObjectAttribute::getCameraViewMat(){
    std::lock_guard<std::mutex> lock(mtx_);
    if(is_updated_[DYNAMICS_ATTRIB]){
        camera_attrib_->setCameraPos(dynamics_attrib_->getTranslation());
        camera_attrib_->setCameraLookAt(dynamics_attrib_->getFaceTo());
        camera_attrib_->setCameraHeadUp(dynamics_attrib_->getHeadUp());
    }
    return camera_attrib_->getViewMat();
}
const GMat4 & ObjectAttribute::getTransformMat(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getTransMat();
}

const GMat4 & ObjectAttribute::getNormalMat(){
    std::lock_guard<std::mutex> lock(mtx_);
    return dynamics_attrib_->getNormMat();
}

void ObjectAttribute::setTranslation(const GVec3 & translation){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[DYNAMICS_ATTRIB] = true;
    dynamics_attrib_->setTrans(translation);
}

void ObjectAttribute::setRotation(const GVec3 & rotation){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[DYNAMICS_ATTRIB] = true;
    dynamics_attrib_->setRot(rotation);
}

void ObjectAttribute::setScale(const GVec3 & scale){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[DYNAMICS_ATTRIB] = true;
    dynamics_attrib_->setScaling(scale);
}

void ObjectAttribute::setColorTexture(const std::string & name){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[APPEARANCEC_ATTRIB] = true;
    appearance_attrib_->setColorTexture(name);
}

void ObjectAttribute::setCubeTexture(const std::string & name){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[APPEARANCEC_ATTRIB] = true;
    appearance_attrib_->setCubeMapTexture(name);
}

void ObjectAttribute::setNormalTexture(const std::string & name){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[APPEARANCEC_ATTRIB] = true;
    appearance_attrib_->setNormalTexture(name);
}
void ObjectAttribute::setObjectColor(const GVec3 obj_color){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[APPEARANCEC_ATTRIB] = true;
    appearance_attrib_->setObjectColor(obj_color);
}

void ObjectAttribute::setCameraRatio(float w_h_ratio){
    std::lock_guard<std::mutex> lock(mtx_);
    is_updated_[CAMERA_ATTRIB] = true;
    camera_attrib_->setRatio(w_h_ratio);
}

bool ObjectAttribute::isAttributeUpdated(const AttributeType & type){
    return is_updated_[type];
}

bool ObjectAttribute::isAttributeActivated(const AttributeType & type){
    return is_activated_[type];
}

GENG_END