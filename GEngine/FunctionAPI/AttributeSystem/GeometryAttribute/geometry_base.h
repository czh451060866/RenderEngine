//
// Created by HongZh on 2022/03/19, 20:22:13
//

#ifndef MYENGINE_GEOMETRY_BASE_H
#define MYENGINE_GEOMETRY_BASE_H

#include "AttributeSystem/attribute_base.h"

GENG_BEGIN

class GeometryBase: public AttributeBase{
public:
    GeometryBase();
    GeometryBase(MeshType mesh_type);
    virtual ~GeometryBase();

    void setMeshType(const MeshType & type);
    const MeshType & getMeshType();
private:
    MeshType mesh_type_ = NONE_MESH;
};

GENG_END

#endif //MYENGINE_GEOMETRY_BASE_H