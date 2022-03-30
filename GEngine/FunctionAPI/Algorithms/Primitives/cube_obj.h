//
// Created by Hong on 2022/2/11.
//

#ifndef MYENGINE_CUBE_OBJ_H
#define MYENGINE_CUBE_OBJ_H

#include "base_obj.h"

GENG_BEGIN

class CubeObject: public BaseObject{
private:
    float length_;
    float width_;
    float height_;
    virtual void generateMesh() override;
public:
    CubeObject();
    ~CubeObject();
};

GENG_END


#endif //MYENGINE_CUBE_OBJ_H
