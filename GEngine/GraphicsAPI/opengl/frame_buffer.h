//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_FRAME_BUFFER_H
#define MYENGINE_FRAME_BUFFER_H

#include "graphic_predeclared.h"
#include "RenderModules/fbo_mod.h"
#include "texture_2d.h"


GENG_BEGIN

class FrameBuffer: public FBOModule{
public:
    FrameBuffer();
    FrameBuffer(uint32_t w, uint32_t h);
    ~FrameBuffer();

    // TODO: only one frame buffer for each time
    virtual void createFBO() override;
    virtual void deleteFBO() override;
    virtual void bindFBO() override;
    virtual void unbindFBO() override;

    // attachment
    virtual void attachTexture(const Texture2D & tex);
    // virtual void drawBuffers();
protected:
    GLuint f_id_;
    std::vector<GLuint> attached_tex_id;
    std::array<GLenum, GL_MAX_COLOR_ATTACHMENTS> attachments_status_;
};

GENG_END

#endif //MYENGINE_FRAME_BUFFER_H
