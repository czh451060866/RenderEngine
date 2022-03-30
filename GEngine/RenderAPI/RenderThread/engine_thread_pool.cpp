//
// Created by zhanghong50 on 2022/1/24.
//

#include "engine_thread_pool.h"

GENG_BEGIN

ThreadPool::ThreadPool() : is_all_stop_(false) {
    for(size_t i = 0; i < MAX_NUM_THREAD; i++){
        thread_pool_[i] = std::thread([this](){
            while(true){
                if(is_all_stop_){
                    break;
                }
                std::unique_lock<std::mutex> locker(mtx_);
                if(task_queue_.empty()){
                    is_queue_empty_.wait(locker);
                }
                else{
                    auto cur_task = std::move(task_queue_.front());
                    task_queue_.pop();
                    locker.unlock(); // do the current task parallely
                    cur_task(); // single task
                }
            }
        });  

        thread_pool_[i].detach();// detach the thread
    }


}

ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> locker(mtx_);
        is_all_stop_ = true; 
    }
    is_queue_empty_.notify_all();
}

ThreadPool & ThreadPool::getInstance() {
    static ThreadPool instance_;
    return instance_;
}

   



GENG_END