//
// Created by 12990 on 2021/9/30.
//

#include "HashCodeUtil.h"
using namespace MemUtil;

HASHCODE HashCodeUtil::hashcode(const std::string &data) {

    long h = 0; // 默认值是0
    if (!data.empty()) {
        const char* val = data.data(); // 字符串对应的char数组

        for (int i = 0; i < data.size(); i++) {
            h = 63 * h + val[i]; // val[0]*63^(n-1) + val[1]*63^(n-2) + ... + val[n-1]
        }
    }
    return h;
}
