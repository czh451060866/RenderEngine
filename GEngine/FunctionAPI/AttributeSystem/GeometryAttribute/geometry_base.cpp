//
// Created by HongZh on 2022/03/19, 20:23:27
//

#include "geometry_base.h"

GENG_BEGIN


GeometryBase::GeometryBase():
AttributeBase(GEOMETRY_ATTRIB){

}

GeometryBase::GeometryBase(MeshType mesh_type):
AttributeBase(GEOMETRY_ATTRIB),
mesh_type_(mesh_type){

}

GeometryBase::~GeometryBase(){

}

const MeshType & GeometryBase::getMeshType(){
    return mesh_type_;
}

void GeometryBase::setMeshType(const MeshType &type){
    mesh_type_ = type;
}

GENG_END