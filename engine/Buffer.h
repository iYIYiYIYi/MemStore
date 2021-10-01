//
// Created by 12990 on 2021/9/23.
//

#ifndef MEMSTORE_BUFFER_H
#define MEMSTORE_BUFFER_H

#include <functional>
#include "Semaphore.h"

namespace MemEngine {
typedef unsigned short USHORT;

#define DEFAULT_LOG_PATH "MemStore.log"

class Buffer {
private:
    USHORT* buffer;    // 缓冲区
    int maxSize;    // 缓冲区最大长度
    int effectiveSize;    // 已经使用长度
    Semaphore* sem;        // 使用信号量保证缓冲区使用互斥
public:
    Buffer(int bufferSize);        // 设置缓冲区大小

    void setEffectiveSize(int size);    // 设置缓冲区已用数据

    void write(std::function<int(USHORT*, int)> const& writeBuffer);    // 将数据写入缓冲区

    void read(std::function<void(USHORT*, int, int)> const& readBuffer);    // 从缓冲区中读取数据

    ~Buffer();
};
}

#endif //MEMSTORE_BUFFER_H
