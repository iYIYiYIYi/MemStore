//
// Created by 12990 on 2021/9/23.
//

#include "EngineLogger.h"
using namespace MemEngine;

Semaphore *EngineLogger::sem  = new Semaphore(1);

EngineLogger *EngineLogger::logger = nullptr;

EngineLogger::EngineLogger() = default;

EngineLogger * EngineLogger::getInstance() {
    if (EngineLogger::logger == nullptr) {
        sem->wait();
        if (EngineLogger::logger == nullptr) {
            EngineLogger::logger = new EngineLogger();
            EngineLogger::logger->_logBuffer = new BufferPool(DEFAULT_LOG_SIZE);
        }
        sem->signal();
    }
    return EngineLogger::logger;
}

bool EngineLogger::_log(const char *data,size_t size) {

    auto *left_size = new size_t(size);
    std::function<int(USHORT *,int)> handler = [data,size,left_size](USHORT *buffer,int buffer_left_size){
        if (size > *left_size) {
            *left_size = size - buffer_left_size;
            int i = 0;
            while (i < buffer_left_size) {
                *(buffer+i) = *(data+i);i++;
            }
        }

        return reinterpret_cast<unsigned long long int *>(size) > left_size ? reinterpret_cast<size_t>(left_size) : size;
    };
    while (*left_size > 0) {
        this->_logBuffer->getBuffer()->write(handler);
        data += (size - *left_size);
    }

    delete left_size;
    return true;
}

bool EngineLogger::log(char *data) {
    size_t i = 0;
    while (*(data+i) != '\0' ) i++;
    return this->_log(data,i);
}

bool EngineLogger::log(const std::string& data) {
    return this->_log(data.data(),data.size());
}



