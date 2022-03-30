//
// Created by zhanghong50 on 2022/1/13.
//

#include "data_buffer.h"

GENG_BEGIN

DataBuffer::DataBuffer() {
    d_id_ = -1;
    b_t_ = GE_ARRAY_BUFFER;
}

DataBuffer::~DataBuffer() {
}

const std::string & DataBuffer::getBufferType() {
    return data_buffer_t[b_t_];
}

void DataBuffer::setUpFloatData(const float *data, const uint32_t  & size) {
    b_t_ = GE_ARRAY_BUFFER;
    createDataBuffer();
    bindDataBuffer();
    transferData(data, size);
    unbindDataBuffer();
}

void DataBuffer::setUpIntData(const uint32_t *data, const uint32_t & size) {
    b_t_ = GE_ELEMENT_ARRAY_BUFFER;
    createDataBuffer();
    bindDataBuffer();
    transferData(data, size);
    unbindDataBuffer();
}


void DataBuffer::setUpLayout(uint32_t loc) {
    loc_ = loc;
    enableVAA();
    bindDataBuffer();
    setVAP();
    unbindDataBuffer();
    disableVAA();
}

void DataBuffer::createDataBuffer() {
    glGenBuffers(1, &d_id_);
}

void DataBuffer::bindDataBuffer()  {
    glBindBuffer(b_t_, d_id_);
}

void DataBuffer::unbindDataBuffer() {
    glBindBuffer(b_t_, 0);
}

void DataBuffer::deleteDataBuffer() {
    glDeleteBuffers(1, &d_id_);
}

// TODO: Paramters
void DataBuffer::transferData(const float *data, const uint32_t & size, const GDRAW_T & draw_t) {
    glBufferData(b_t_, sizeof(float) * size, data, draw_t);
}

void DataBuffer::transferData(const uint32_t *data, const uint32_t & size, const GDRAW_T & draw_t) {
    glBufferData(b_t_, sizeof(uint32_t) * size, data, draw_t);
}

void DataBuffer::enableVAA() {
    glEnableVertexAttribArray(loc_);
}

void DataBuffer::disableVAA() {
    glDisableVertexAttribArray(loc_);
}

// TODO: params
void DataBuffer::setVAP() {
        glVertexAttribPointer(loc_, 3, GL_FLOAT, false, 3*sizeof(float), (void* ) 0);
}



GENG_END