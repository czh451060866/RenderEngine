//
// Created by zhanghong50 on 2022/1/23.
//

#include "render_queue.h"

GENG_BEGIN

RenderQueue::RenderQueue() {

}

RenderQueue::~RenderQueue() {

}

void RenderQueue::pushQueue(const std::shared_ptr<RenderData> &data) {
    std::lock_guard<std::mutex> lock(mtx_);
    render_queue_.push(data);
}

std::shared_ptr<RenderData> RenderQueue::queryAndPopQueue() {
    std::lock_guard<std::mutex> lock(mtx_);
    if(!render_queue_.empty()){
        std::shared_ptr<RenderData> data = render_queue_.front();
        render_queue_.pop();
        return data;
    }
    return nullptr;
}

bool RenderQueue::isEmpty() {
    std::lock_guard<std::mutex> lock(mtx_);
    return render_queue_.empty();
}

void RenderQueue::emptyQueue() {
    std::lock_guard<std::mutex> lock(mtx_);
    if(!render_queue_.empty()){
        std::queue<std::shared_ptr<RenderData>> empty;
        render_queue_.swap(empty);
    }
}

GENG_END