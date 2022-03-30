//
// Created by Hong on 2022/2/15.
//

#ifndef MYENGINE_TRANSFORMER_BASE_H
#define MYENGINE_TRANSFORMER_BASE_H

#include "AttributeSystem/attribute_base.h"

GENG_BEGIN

class TransformerBase: public AttributeBase{
public:
    TransformerBase();
    virtual ~TransformerBase();

    void setTrans(const GVec3 & vec);
    void setRot(const GVec3 & rot);
    void setScaling(const GVec3 & scale);

    const GMat4 & getTransMat();
    const GMat4 & getNormMat();
    const GMat4 & getRotMat();
    const GVec3 & getTranslation();
    const GVec3 & getRotation();
    const GVec3 & getScale();
    const GVec3 & getFaceTo();
    const GVec3 & getHeadUp();
    const GVec3 & getRightSide();
    
protected:
    GVec3 translation_ = GVec3(0.0f);
    GVec3 rotation_ = GVec3(0.0f);
    GVec3 scale_factor_ = GVec3(1.0f);

    GVec3 face_to_= GVec3(0.0f, 0.0f, 1.0f);
    GVec3 head_up_= GVec3(0.0f, 1.0f, 0.0f);
    GVec3 right_side_= GVec3(-1.0f, 0.0f, 0.0f);

    GMat4 trans_mat_ = GMat4(1.0f);
    GMat4 norm_mat_ = GMat4(1.0f);    // normal transformation for normals 
    GMat4 rot_mat_ = GMat4(1.0f);

    std::mutex mtx_;    // locker
    // functions
    void updateTransMat();

};

GENG_END


#endif //MYENGINE_TRANSFORMER_BASE_H
