//
// Created by zhanghong50 on 2022/1/24.
//

#ifndef MYENGINE_ENGINE_THREAD_POOL_H
#define MYENGINE_ENGINE_THREAD_POOL_H

#include "thread_predeclared.h"
#include <condition_variable>
#include <mutex>


GENG_BEGIN


class ThreadPool {
private:
    std::array<std::thread, MAX_NUM_THREAD> thread_pool_;
    std::queue<std::function<void()>> task_queue_;
    bool is_all_stop_;
    std::mutex mtx_;
    std::condition_variable is_queue_empty_;
    ThreadPool();

public:
    ~ThreadPool();
    static ThreadPool & getInstance();
    ThreadPool(const ThreadPool&)=delete;
    ThreadPool& operator=(const ThreadPool&)=delete;

    template<class F, class ... Argv>
    void submitTask(F&& f, Argv&& ... argv){
        auto && task = std::bind(std::forward<F>(f), std::forward<Argv>(argv)...);
        {
            std::lock_guard<std::mutex> locker(mtx_); 
            task_queue_.emplace(task);
        }
        is_queue_empty_.notify_one();
    }
};


GENG_END


#endif //MYENGINE_ENGINE_THREAD_POOL_H
