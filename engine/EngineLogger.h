//
// Created by 12990 on 2021/9/23.
//

#ifndef MEMSTORE_ENGINELOGGER_H
#define MEMSTORE_ENGINELOGGER_H

#include "BufferPool.h"

namespace MemEngine {

#define DEFAULT_LOG_SIZE 80

class EngineLogger {
private:
    BufferPool *_logBuffer{};

    EngineLogger static *logger;

    Semaphore static *sem;

    EngineLogger();

    bool _log(const char *data,size_t size);
public:
    static EngineLogger* getInstance();

    bool log(char* data);

    bool log(const std::string& data);
};

}


#endif //MEMSTORE_ENGINELOGGER_H
