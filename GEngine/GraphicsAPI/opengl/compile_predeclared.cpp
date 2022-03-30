//
// Created by zhanghong50 on 2022/1/28.
//

#include "RenderLog/render_log.h"
#include "complie_predeclared.h"

GENG_BEGIN

InitGraphic::InitGraphic() {
    RenderLog & render_log = RenderLog::getInstance();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        render_log.submitLog("Error: %s\n", glewGetErrorString(err));
    }
    render_log.submitLog("%s\n", "GLEW::Initialization");
}


InitGraphic::~InitGraphic() {

}

GENG_END