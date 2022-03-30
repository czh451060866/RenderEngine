//
// Created by zhanghong50 on 2022/2/11.
//

#include "camera_base.h"

GENG_BEGIN

CameraBase::CameraBase():
AttributeBase(CAMERA_ATTRIB) {
}

CameraBase::~CameraBase() {

}

void CameraBase::computePerspectiveMat() {
    projection_mat_ = GPerspective(GRadians(FOV_), w_h_ratio_, near_plane_, far_plane_);
}

//void CameraBase::computeOrthoMat() {
//    ortho_mat_ = GOrtho()
//}

void CameraBase::computeViewMat() {
    view_mat_ = GLookAt(pos_, look_at_, head_up_);
}

const GMat4 & CameraBase::getViewMat() {
    computeViewMat();
    return view_mat_;
}

const GVec3 & CameraBase::getCameraPos() {
    return pos_;
}

const GMat4 & CameraBase::getPerspectiveMat() {
    computePerspectiveMat();
    return projection_mat_;
}

const CameraType & CameraBase::getCameraType() {
    return camera_type_;
}

void CameraBase::setFOV(const float & fov) {
    FOV_ = fov;
}

void CameraBase::setRatio(const float & w_h_ratio) {
    w_h_ratio_ = w_h_ratio;
}

void CameraBase::setNearPlane(const float & near) {
    near_plane_ = near;
}

void CameraBase::setFarPlane(const float & far) {
    far_plane_ = far;
}

void CameraBase::setCameraPos(const GVec3 &pos){
    pos_ = pos;
}

void CameraBase::setCameraLookAt(const GVec3 & face_to){
    look_at_ =  pos_ - face_to;
}

void CameraBase::setCameraHeadUp(const GVec3 &head_up){
    head_up_ = head_up;
}





GENG_END