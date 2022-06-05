#include "12_2.h"
#include <iostream>

int main()
{
    const StrBlob csb{ "hello", "world", "pezy" };
    StrBlob sb = csb;

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "sherlolo";
    std::cout << sb.front() << " " << sb.back() << std::endl;
    std::cout << csb.front() << " " << csb.back() << std::endl;
    system("pause");
    return 0;
} 