//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_PLANE_OBJ_H
#define MYENGINE_PLANE_OBJ_H

#include "base_obj.h"

GENG_BEGIN

class PlaneObject: public BaseObject {
private:
    float width_;
    float height_;
    virtual void generateMesh() override;

public:
    PlaneObject();
    ~PlaneObject();
};

GENG_END


#endif //MYENGINE_PLANE_OBJ_H
