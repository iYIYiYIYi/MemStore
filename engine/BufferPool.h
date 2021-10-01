//
// Created by 12990 on 2021/9/23.
//

#ifndef MEMSTORE_BUFFERPOOL_H
#define MEMSTORE_BUFFERPOOL_H

#include "Buffer.h"

namespace MemEngine {
#define DEFAULT_BUFFER_SIZE 512

class BufferPool {
private:
    int head, tail;    // 头尾指针
    Buffer** buffers;    // 缓冲池
    int total, length;    // 缓冲区总个数和以使用个数

public:
    explicit BufferPool(int count = 10, int bufferSize = DEFAULT_BUFFER_SIZE);  // 构造函数  count:缓冲区个数  bufferSize:缓冲区大小

    Buffer* getBuffer();    // 获取一个缓冲区

    Buffer* getBuffer_S();

    Buffer* popBuffer();    // 取得头缓冲区并弹出

    bool empty() const;        // 缓冲池是否为空

    bool full() const;        // 缓冲池是否已满

    ~BufferPool();
};
}


#endif //MEMSTORE_BUFFERPOOL_H
