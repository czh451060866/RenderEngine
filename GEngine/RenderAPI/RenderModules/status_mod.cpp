//
// Created by HongZh on 2022/02/25, 11:27:00
//

#include "status_mod.h"
#include "status_call.h"

GENG_BEGIN


StatusModule::StatusModule(){
    
}

StatusModule::~StatusModule(){

}

std::shared_ptr<StatusModule> StatusModule::getInstancePtr(){
    std::shared_ptr<StatusModule> instance_ptr = std::make_shared<StatusCall>();
    return instance_ptr;
}


StatusManager::StatusManager(){
    status_ptr_ = StatusModule::getInstancePtr();
    // default5
    // TODO
    status_ptr_->setFaceCull(CullFace_);
    status_ptr_->setDepthTest(DepthTest_);
}

StatusManager::~StatusManager(){
    
}

void StatusManager::clearColorBuffer(){
    status_ptr_->clearColorBuffer();
}

void StatusManager::clearDepthBuffer(){
    status_ptr_->clearDepthBuffer();
}

void StatusManager::clearAllBuffer(){
    status_ptr_->clearColorBuffer();
    status_ptr_->clearDepthBuffer();
}

void StatusManager::saveCurStatus(){
    status_ptr_->checkFaceCull(CullFace_);
    status_ptr_->checkDepthTest(DepthTest_);
}

void StatusManager::resetStatus(){
    status_ptr_->setFaceCull(CullFace_);
}



GENG_END