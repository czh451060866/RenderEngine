//
// Created by HongZh on 2022/02/25, 14:44:59
//

#include "status_call.h"

GENG_BEGIN

StatusCall::StatusCall(){

}

StatusCall::~StatusCall(){

}

void StatusCall::setFaceCull(const int32_t & var){
    if(var){
        glEnable(GL_CULL_FACE);
    }
    else{
        glDisable(GL_CULL_FACE);
    }
}
void StatusCall::checkFaceCull(int32_t & var){
    glGetIntegerv(GL_CULL_FACE, &var);
}

void StatusCall::setDepthTest(const int32_t & var){
    if(var){
        glEnable(GL_DEPTH_TEST); 
        glDepthFunc(GL_LESS); 
    }
    else{
        glDisable(GL_DEPTH_TEST);
    }
}
void StatusCall::checkDepthTest(int32_t & var){
    glGetIntegerv(GL_DEPTH_TEST, &var);
}

void StatusCall::clearColorBuffer(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void StatusCall::clearDepthBuffer(){
    glClear(GL_DEPTH_BUFFER_BIT);
}



GENG_END