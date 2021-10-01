//
// Created by 12990 on 2021/9/23.
//

#include "Buffer.h"
#include<fstream>

using namespace MemEngine;

Buffer::Buffer(int size) {
    this->maxSize = size;
    this->effectiveSize = 0;
    this->buffer = new USHORT[size];
    this->sem = new Semaphore(1);
}

void Buffer::setEffectiveSize(int size) {
    this->effectiveSize = size;
}

/**
* 将数据写入缓冲区，互斥操作
* writeBuffer: lambda表达式，接受参数为  USHORT*:缓冲区数据 int:缓冲区最大长度, 返回int:写入数据的长度
*/
void Buffer::write(std::function<int(USHORT*, int)> const& writeBuffer) {
    this->sem->wait();
    this->effectiveSize = writeBuffer(this->buffer, this->maxSize - this->effectiveSize);
    this->sem->signal();
}

/**
* 读取缓冲区数据，互斥操作
* readBuffer: lambda表达式，接受参数为  USHORT*:缓冲区数据 int:缓冲区有效长度 int:缓冲区最大长度  返回void
*/
void Buffer::read(std::function<void(USHORT*, int, int)> const& readBuffer) {
    this->sem->wait();
    readBuffer(this->buffer, this->effectiveSize, this->maxSize);
    this->sem->signal();
}
Buffer::~Buffer() {
    delete[] buffer;
    delete sem;
}
