//
// Created by 12990 on 2021/9/30.
//

#ifndef MEMSTORE_HASHCODEUTIL_H
#define MEMSTORE_HASHCODEUTIL_H

#include <string>

namespace MemUtil{
typedef long HASHCODE;

class HashCodeUtil {

public:
    static HASHCODE hashcode(const std::string &data);
};

};



#endif //MEMSTORE_HASHCODEUTIL_H
