//
// Created by 12990 on 2021/9/23.
//

#ifndef MEMSTORE_SEMAPHORE_H
#define MEMSTORE_SEMAPHORE_H

#include <mutex>
#include <condition_variable>

namespace MemEngine {
class Semaphore {
private:
    std::mutex mutex{};    // 互斥量
    std::condition_variable cv{};    // 条件变量
    int count;    // 可用资源数
public:
    explicit Semaphore(int count = 0);

    void signal();    // 释放一个资源

    void wait();    // 等待一个资源
};

}

#endif //MEMSTORE_SEMAPHORE_H
