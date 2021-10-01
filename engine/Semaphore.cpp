//
// Created by 12990 on 2021/10/1.
//

#include "Semaphore.h"

using namespace MemEngine;

Semaphore::Semaphore(int count) {
    if (count < 0) { throw "可用资源不能小于0"; }
    this->count = count;
}

/**
* 释放资源
*/
void Semaphore::signal() {
    std::unique_lock<std::mutex> lock(this->mutex);
    ++this->count;
    this->cv.notify_one();
}

/**
* 申请资源
*/
void Semaphore::wait() {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->cv.wait(lock, [=] { return count > 0; });        // reutrn true时往下执行
    --this->count;
}