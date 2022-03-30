//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_DATA_BUFFER_H
#define MYENGINE_DATA_BUFFER_H

#include "graphic_predeclared.h"
#include "RenderModules/data_mod.h"

GENG_BEGIN

class DataBuffer: public DataModule{
protected:
    uint32_t d_id_;
    uint32_t attr_id_;
    uint32_t loc_; // loc in shader
    std::string name_;
    GBUFFER_T b_t_;

public:
    DataBuffer();
    ~DataBuffer();

    virtual const std::string & getBufferType() override;

    // data buffer
    virtual void createDataBuffer();
    virtual void deleteDataBuffer();
    virtual void bindDataBuffer() override;
    virtual void unbindDataBuffer() override;
    virtual void transferData(const float * data, const uint32_t & size, const GDRAW_T & draw_t = GE_STATIC_DRAW);
    virtual void transferData(const uint32_t * data, const uint32_t & size, const GDRAW_T & draw_t = GE_STATIC_DRAW);
    // attribute buffer
    virtual void enableVAA() override;
    virtual void disableVAA() override;
    // TODO:
    virtual void setVAP();

//    virtual void linkToShader();

//    void setUpFloatData(float *data) override;
//    void setUpIntData(int *data) override;
    void setUpFloatData(const float *data, const uint32_t & size) override;
    void setUpIntData(const uint32_t *data, const uint32_t & size) override;
    void setUpLayout(uint32_t loc) override;
};
GENG_END

#endif //MYENGINE_DATA_BUFFER_H
