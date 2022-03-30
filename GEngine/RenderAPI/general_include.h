//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_GENERAL_INCLUDE_H
#define MYENGINE_GENERAL_INCLUDE_H

#include "basic_include.h"
#include <mutex>
#include <chrono>
#include <condition_variable>

GENG_BEGIN
enum MeshType{
    NONE_MESH = 0,
    PREDECLARED_SKYBOX,
    PREDECLARED_PLANE,
    PREDECLARED_CUBE,
    PREDECLARED_SPHERE,
    IMPORTED_MODEL,
    HEIGHT_MAP
};

enum ModelType{
    NONE_MODEL = 0,
    MODEL_OBJ,
    MODEL_PLY,
    MODEL_FBX
};

enum LightType{
    NONE_LIGHT = 0,
    POINT_LIGHT,
    DIRECTIONAL_LIGHT,
    LINE_LIGHT,
    AREA_LIGHT,
    FULL_LIGHT
};

enum CameraType{
    NONE_CAMERA = 0,
    PINHOLE_CAMERA,
    LENS_CAMERA
};

enum TextureType {
    ColorTexture = 0,
    NormalTexture, 
    RoughTexture,
    BumpTexture,
    CubeMapTexture,
    DisplacementTexture
}; 

static std::map<TextureType, std::string> tex_prefix = {
    {ColorTexture, "ColorTexture"},
    {NormalTexture, "NormalTexture"},
    {BumpTexture, "BumpTexture"},
    {RoughTexture, "RoughTexture"},
    {CubeMapTexture, "CubeMapTexture"},
    {DisplacementTexture, "DisplacementTexture"}
};

enum DynamicsType{
    NONE_DYNAMICS = 0,
    RIGID_DYNAMICS,
    SOFT_DYNAMICS,
    FLUID_DYNAMICS
};

enum GeometryType{
    NONE_GEOMETRY = 0,
    RIDID_GEOMETRY,
    DEFORMABLE_GEOMETRY
};

enum AppearanceType{
    NONE_APPEARANCE = 0,
    TEXTURE_APPEARANCE
};


GENG_END

#endif //MYENGINE_GENERAL_INCLUDE_H
