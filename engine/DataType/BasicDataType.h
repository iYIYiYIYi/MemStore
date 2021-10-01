//
// Created by 12990 on 2021/9/30.
//

#ifndef MEMSTORE_BASICDATATYPE_H
#define MEMSTORE_BASICDATATYPE_H

#include <string>

namespace MemEngine {
template<typename V>
struct entry_list {
    std::string key;
    V value;
    linked_list *next = nullptr;

};

template<typename V>
struct entry {
    std::string key;
    V value;
};

class BasicDataType {
public:
    const std::string &key;
    void* data_ptr;
    size_t data_length;

    BasicDataType *next;

    BasicDataType(const std::string &key, void *dataPtr);

    BasicDataType(const std::string &key, void *dataPtr, size_t dataLength);

    BasicDataType(const std::string &key, void *dataPtr, size_t dataLength, BasicDataType *next);
};
}



#endif //MEMSTORE_BASICDATATYPE_H
