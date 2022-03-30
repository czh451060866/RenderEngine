//
// Created by Hong on 2022/2/15.
//

#include "transformer_base.h"
#include "engine_math.h"
#include "glm/gtc/matrix_transform.hpp"

GENG_BEGIN

TransformerBase::TransformerBase():
AttributeBase(DYNAMICS_ATTRIB) {
}

TransformerBase::~TransformerBase() {

}

void TransformerBase::updateTransMat() {
    GMat4 Identity = GMat4(1.0f);
    rot_mat_ = GMat4(1.0f);

    trans_mat_ = GScale(Identity, scale_factor_); 
    rot_mat_ = GRotate(rot_mat_, rotation_[0], GVec3(1.0f, 0.0f, 0.0f));
    rot_mat_ = GRotate(rot_mat_, rotation_[1], GVec3(0.0f, 1.0f, 0.0f));
    rot_mat_ = GRotate(rot_mat_, rotation_[2], GVec3(0.0f, 0.0f, 1.0f));
    // TODO
    GMat4 translation = GTranslate(Identity, translation_);   // finally, translation
    trans_mat_ = translation * rot_mat_ * trans_mat_;
   
    // norm mat
    norm_mat_ = GInverse(rot_mat_);
    norm_mat_ = GScale(norm_mat_, GVec3(1.0/scale_factor_.x, 1.0/scale_factor_.y, 1.0/scale_factor_.z));
    norm_mat_ = Gtranspose(norm_mat_);

    // update the pose of object
    face_to_ = rot_mat_[2];
    head_up_ = rot_mat_[1];
    right_side_ = -rot_mat_[0];
}

void TransformerBase::setTrans(const GVec3 &vec){
    std::lock_guard<std::mutex> locker(mtx_);
    translation_ = vec;
}

void TransformerBase::setRot(const GVec3 &rot){
    std::lock_guard<std::mutex> locker(mtx_);
    rotation_ = rot;
}

void TransformerBase::setScaling(const GVec3 &scale){
    std::lock_guard<std::mutex> locker(mtx_);
    scale_factor_ = scale;
}

const GVec3 & TransformerBase::getTranslation(){
    std::lock_guard<std::mutex> locker(mtx_);
    return translation_;
}

const GVec3 & TransformerBase::getRotation(){
    std::lock_guard<std::mutex> locker(mtx_);
    return rotation_;
}

const GVec3 & TransformerBase::getScale(){
    std::lock_guard<std::mutex> locker(mtx_);
    return scale_factor_;
}

const GVec3 & TransformerBase::getFaceTo(){
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return face_to_;
}

const GVec3 & TransformerBase::getHeadUp(){
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return head_up_;
}

const GVec3 & TransformerBase::getRightSide(){
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return right_side_;
}

const GMat4 & TransformerBase::getTransMat() {
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return trans_mat_;
}

const GMat4 & TransformerBase::getRotMat(){
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return rot_mat_;
}

const GMat4 & TransformerBase::getNormMat(){
    std::lock_guard<std::mutex> locker(mtx_);
    updateTransMat();
    return norm_mat_;
}

GENG_END