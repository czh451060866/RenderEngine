//
// Created by zhanghong50 on 2022/2/11.
//

#ifndef MYENGINE_CAMERA_BASE_H
#define MYENGINE_CAMERA_BASE_H

#include "AttributeSystem/attribute_base.h"

GENG_BEGIN

class CameraBase: public AttributeBase{
public:
    CameraBase();
    virtual ~CameraBase();

    void computeViewMat();
    void computePerspectiveMat();

    // get
    const GVec3 & getCameraPos();
    const GMat4 & getViewMat();
    const GMat4 & getPerspectiveMat();
    const CameraType & getCameraType();

    // set
    void setCameraPos(const GVec3 & pos);
    void setCameraLookAt(const GVec3 & face_to);
    void setCameraHeadUp(const GVec3 & head_up);
    void setFOV(const float & fov);
    void setRatio(const float & w_h_ratio);
    void setNearPlane(const float & near);
    void setFarPlane(const float & far);
    
protected:
    GVec3 pos_;
    GVec3 look_at_;
    GVec3 head_up_;

    GMat4 view_mat_;
    GMat4 projection_mat_;
    GMat4 ortho_mat_;


    float w_h_ratio_ = 1.0f;
    float FOV_ = 45.0;
    float near_plane_ = 0.1f;
    float far_plane_ = 100.0f;

    CameraType camera_type_ = PINHOLE_CAMERA;
};

GENG_END


#endif //MYENGINE_CAMERA_BASE_H
