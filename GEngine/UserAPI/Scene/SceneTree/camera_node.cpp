//
// Created by zhanghong50 on 2022/1/20.
//

#include "camera_node.h"

GENG_BEGIN

CameraNode::CameraNode() {
    camera_label_ = PINHOLE_CAMERA;
    node_type_ = CAMERA_NODE;
}

CameraNode::CameraNode(CameraType type) {
    camera_label_ = type;
    node_type_ = CAMERA_NODE;
}

CameraNode::~CameraNode() {

}

CameraType CameraNode::getCameraLabel() {
    return camera_label_;
}

GENG_END