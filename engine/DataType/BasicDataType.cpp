//
// Created by 12990 on 2021/9/30.
//

#include "BasicDataType.h"
using namespace MemEngine;

BasicDataType::BasicDataType(const std::string &key, void *dataPtr) : key(key), data_ptr(dataPtr)
{
    data_length = sizeof(dataPtr);
    next = nullptr;
}

BasicDataType::BasicDataType(const std::string &key, void *dataPtr, size_t dataLength) : key(key), data_ptr(dataPtr),data_length(dataLength)
{
    next = nullptr;
}

BasicDataType::BasicDataType(const std::string &key, void *dataPtr, size_t dataLength, BasicDataType *next) : key(key),
                                                                                                              data_ptr(dataPtr),
                                                                                                              data_length(dataLength),
                                                                                                              next(next)
{

}
