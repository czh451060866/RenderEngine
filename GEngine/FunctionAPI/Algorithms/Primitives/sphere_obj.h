//
// Created by HongZh on 2022/02/20, 23:48:20
//

#ifndef MYENGINE_SPHERE_OBJ_H
#define MYENGINE_SPHERE_OBJ_H

#include "base_obj.h"

GENG_BEGIN

class SphereObject: public BaseObject{
public:
    SphereObject();
    ~SphereObject();

    void setRadius(const float & r);
    void setNumOfStack(const float & n_stack);
    void setNumOfSector(const float & n_sector);
    void setStackRange(const float & stack_range);
    void setSectorRange(const float & sector_range);
private:
    float radius_;
    float sector_range_;
    float stack_range_;
    uint32_t num_sector_;
    uint32_t num_stack_;

    virtual void generateMesh() override;

};

GENG_END

#endif //MYENGINE_SPHERE_OBJ_H