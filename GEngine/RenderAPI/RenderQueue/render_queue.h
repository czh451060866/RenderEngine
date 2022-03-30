//
// Created by zhanghong50 on 2022/1/23.
//

#ifndef MYENGINE_RENDER_QUEUE_H
#define MYENGINE_RENDER_QUEUE_H

#include "general_include.h"
#include "render_data.h"

GENG_BEGIN

class RenderQueue {
public:
    RenderQueue();
    ~RenderQueue();

    virtual void pushQueue(const std::shared_ptr<RenderData> & data);
    virtual std::shared_ptr<RenderData> queryAndPopQueue();

    bool isEmpty();
    void emptyQueue();

protected:
    std::queue<std::shared_ptr<RenderData>> render_queue_;
    std::mutex mtx_;

};

GENG_END


#endif //MYENGINE_RENDER_QUEUE_H
