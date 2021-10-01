#include <iostream>
#include "Util/HashCodeUtil.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string s = "hello";
    std::string s1 = "clarques";
    MemUtil::HASHCODE hash = MemUtil::HashCodeUtil::hashcode(s);
    MemUtil::HASHCODE hash1 = MemUtil::HashCodeUtil::hashcode(s1);
    std::cout<<"hello hash:"<<hash<<" clarques hash:"<<hash1<<std::endl;

    return 0;
}
