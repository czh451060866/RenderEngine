//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_BASIC_INCLUDE_H
#define MYENGINE_BASIC_INCLUDE_H


#include <string>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <functional>

#define GENG_BEGIN namespace gEngine{
#define  GENG_END }

GENG_BEGIN

enum AttributeKey {
    UNKNOW_KEY = 0x300,
    VERTEX_POSITION,
    TEXTURE_COORDINATE,
    VERTEX_NORMAL,
    VERTEX_TANGENT,
    VERTEX_BITANGENT
};

enum UniformKey {
    LIGHT_COLOR = 0x00,
    LIGHT_DIR,
    LIGHT_POSITION,
    CAMERA_VIEW_MAT,
    CAMERA_POSITION,
    CAMERA_PROSPECTIVE_MAT,
    OBJECT_COLOR,
    MODEL_MAT,
    NORM_MAT,
    TEX_LOD,
    ALBEDO,
    METALLIC,
    ROUGHNESS,
    AO
};

static std::map<uint32_t , std::string> remain_key ={
    {VERTEX_POSITION, "Pos"},
    {TEXTURE_COORDINATE, "UV"},
    {VERTEX_NORMAL, "Norm"},
    {VERTEX_TANGENT, "Tangent"},
    {VERTEX_BITANGENT, "Bitangent"},
    {OBJECT_COLOR, "ObjectColor"},
    {LIGHT_POSITION, "LightPos"},
    {LIGHT_COLOR, "LightColor"},
    {LIGHT_DIR, "LightDir"},
    {CAMERA_POSITION, "CameraPos"},
    {CAMERA_VIEW_MAT, "ViewMat"},
    {CAMERA_PROSPECTIVE_MAT, "ProjMat"},
    {MODEL_MAT, "ModelMat"},
    {NORM_MAT, "NormMat"},
    {TEX_LOD, "Lod"},
    {ALBEDO, "albedo"},
    {METALLIC, "metallic"},
    {ROUGHNESS, "roughness"},
    {AO, "ao"}
};


GENG_END

#endif //MYENGINE_BASIC_INCLUDE_H
