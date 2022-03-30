//
// Created by zhanghong50 on 2022/1/19.
//

#ifndef MYENGINE_DATA_MOD_H
#define MYENGINE_DATA_MOD_H

#include "general_include.h"

GENG_BEGIN

class DataModule {
public:
    static std::shared_ptr<DataModule> getInstancePtr();
    virtual ~DataModule();
    
    virtual const std::string & getBufferType() = 0;
    virtual void bindDataBuffer() = 0;
    virtual void unbindDataBuffer() = 0;
    virtual void enableVAA() = 0;
    virtual void disableVAA() = 0;
    virtual void setUpFloatData(const float * data, const uint32_t & size) = 0;
    virtual void setUpIntData(const uint32_t * data, const uint32_t & size) = 0;
    virtual void setUpLayout(uint32_t loc) = 0;
    const AttributeKey & getDataLayOut();
    void setDataLayOut(AttributeKey key);

protected:
    AttributeKey attrib_key_;
    DataModule();
};

GENG_END


#endif //MYENGINE_DATA_MOD_H
