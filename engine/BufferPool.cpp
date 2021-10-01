//
// Created by 12990 on 2021/9/23.
//

#include "BufferPool.h"
using namespace MemEngine;

BufferPool::BufferPool(int count, int bufferSize) {
    this->head = 0;
    this->tail = 0;
    this->length = 0;
    this->total = count;

    this->buffers = new Buffer*[count];
    for (int i = 0; i < count; i ++) {
        this->buffers[i] = new Buffer(bufferSize);
    }
}

/**
* 获取一个缓冲区 当缓冲池已满时，覆盖旧数据
*/
Buffer* BufferPool::getBuffer() {
    Buffer* buffer = this->buffers[this->tail];
    // tail指针指向下一个缓冲区，如果当前缓冲池已满，头指针下移
    this->tail = (this->tail + 1) % this->total;
    this->length++;
    if (this->length > this->total) {
        this->head = (this->head + 1) % this->total;
        this->length = this->total;
    }
    return buffer;
}

/**
* 获取头缓冲区并弹出
*/
Buffer* BufferPool::popBuffer() {
    if (this->length == 0) { throw "No buffer left"; }
    Buffer* buffer = this->buffers[this->head];
    this->head = (this->head + 1) % this->total;
    this->length--;
    return buffer;
}

BufferPool::~BufferPool() {
    for (int i = 0; i < this->total; i ++) {
        delete this->buffers[i];
        this->buffers[i] = nullptr;
    }
    delete this->buffers;
    this->buffers = nullptr;
}

bool BufferPool::empty() const {
    return this->length == 0;
}

bool BufferPool::full() const {
    return this->length == this->total;
}

/**
 * 获取缓冲区，如果满了则抛出异常
 * @return
 */
Buffer *BufferPool::getBuffer_S() {
    if (this->length >= this->total) {
        throw "Buffer Pool Overflow";
    }
    Buffer* buffer = this->buffers[this->tail];
    // tail指针指向下一个缓冲区，如果当前缓冲池已满，头指针下移
    this->tail = (this->tail + 1) % this->total;
    this->length++;
    return buffer;
}
