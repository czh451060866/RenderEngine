//
// Created by HongZh on 2022/03/19, 19:17:22
//

#ifndef MYENGINE_OBJECT_ATTRIBUTE_H
#define MYENGINE_OBJECT_ATTRIBUTE_H

#include "attribute_base.h"
#include "AppearanceAttribute/texture_base.h"
#include "GeometryAttribute/geometry_base.h"
#include "DynamicsAttribute/transformer_base.h"
#include "CameraAttribute/camera_base.h"
#include "IlluminousAttribute/lighting_include.h"


GENG_BEGIN

struct AttribInfo{
    std::string name;
    MeshType mesh_type_ = NONE_MESH;
    CameraType camera_type_ = NONE_CAMERA;
    LightType light_type_ = NONE_LIGHT;
    GeometryType geo_type_ = NONE_GEOMETRY;
    DynamicsType dynam_type_ = RIGID_DYNAMICS;
    AppearanceType appearance_type = TEXTURE_APPEARANCE;
};

// TODO: Safety Check
class ObjectAttribute{
public:
    ObjectAttribute();
    ~ObjectAttribute();

    const GVec3 & getObjectPosition();  // unsafe call, please check if the sub_attribute is available
    const GVec3 & getObjectRotation();
    const GVec3 & getObjectScale();
    const GVec3 & getObjectFaceTo();
    const GVec3 & getObjectHeadUp();
    const GVec3 & getObjectRightSide();
    const GVec3 & getObjectColor();
    const GMat4 & getCameraProjMat();
    const GMat4 & getCameraViewMat();
    const GMat4 & getTransformMat();
    const GMat4 & getNormalMat();   
    const std::string & getColorTexture();
    const std::string & getNormalTexture();
    const std::string & getCubeMap();
    const LightType & getLightType();
    const CameraType & getCameraType();

    void addAttribute(const AttribInfo & attrib_info);
    void setTranslation(const GVec3 & translation);
    void setRotation(const GVec3 & rotation);
    void setScale(const GVec3 & scale);
    void setColorTexture(const std::string & name);
    void setCubeTexture(const std::string & name);
    void setNormalTexture(const std::string & name);
    void setObjectColor(const GVec3 obj_color);
    void setCameraRatio(float w_h_ratio);
    
    bool isAttributeUpdated(const AttributeType & type);
    bool isAttributeActivated(const AttributeType & type); 

private:
    std::shared_ptr<TextureBase> appearance_attrib_;
    std::shared_ptr<CameraBase> camera_attrib_;
    std::shared_ptr<TransformerBase> dynamics_attrib_;
    std::shared_ptr<LightBase> illuminious_attrib_;
    std::shared_ptr<GeometryBase> geometry_attrib_;

    // basic attributes: pose
    // GVec3 obj_pos_ = GVec3(0.0f);
    // GVec3 face_to_= GVec3(0.0f, 0.0f, 1.0f);
    // GVec3 head_up_= GVec3(0.0f, 1.0f, 0.0f);
    // GVec3 right_side_= GVec3(-1.0f, 0.0f, 0.0f);

    std::unordered_map<AttributeType, bool> is_updated_ = {
        {GEOMETRY_ATTRIB, true},
        {DYNAMICS_ATTRIB, true},
        {CAMERA_ATTRIB, true},
        {ILLUMINOUS_ATTRIB, true},
        {APPEARANCEC_ATTRIB, true}
    }; // attribute states
    std::unordered_map<AttributeType, bool> is_activated_ = {
        {GEOMETRY_ATTRIB, true},
        {DYNAMICS_ATTRIB, true},
        {CAMERA_ATTRIB, true},
        {ILLUMINOUS_ATTRIB, true},
        {APPEARANCEC_ATTRIB, true}
    };

    std::mutex mtx_; // TODO CS
};

GENG_END

#endif //MYENGINE_OBJECT_ATTRIBUTE_H