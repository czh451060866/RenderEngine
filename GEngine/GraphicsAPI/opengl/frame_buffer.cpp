//
// Created by zhanghong50 on 2022/1/13.
//

#include "frame_buffer.h"


GENG_BEGIN


FrameBuffer::FrameBuffer() {
    width_ = 0;
    height_ = 0;
    f_id_ = 0;
    createFBO();
}
FrameBuffer::FrameBuffer(uint32_t w, uint32_t h) {
    width_ = w;
    height_ = h;
    f_id_ = 0;
    createFBO();
}

// TODO: texture delete
FrameBuffer::~FrameBuffer() {
    deleteFBO();
}

void FrameBuffer::createFBO() {
    glGenFramebuffers(1, &f_id_);
}

void FrameBuffer::deleteFBO() {
    if(f_id_ != 0){
        glDeleteFramebuffers(1, &f_id_);
    }
}

void FrameBuffer::bindFBO() {
    glBindFramebuffer(GL_FRAMEBUFFER, f_id_);
}

void FrameBuffer::unbindFBO() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// TODO: 1D, 3D
void FrameBuffer::attachTexture(const Texture2D &tex) {
    switch (tex.tex_dimension_) {
        case GE_TEXTURE_2D:{
            attached_tex_id.push_back(tex.tex_id_);
            // TODO
            glFramebufferTexture2D(GL_FRAMEBUFFER, attachment_t[tex.tex_type_],  tex.tex_dimension_, tex.tex_id_, 0);
            break;
        }
        default:
            break;
    }

}



GENG_END