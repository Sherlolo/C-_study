#include <iostream>
#include "mytime.cpp"

int main()
{
    Time t1(12,20);
    Time t2(13,30);
    double m = 12;
    std::cout << "t1 + t2: " << t1 + t2 << std::endl;
    std::cout << "t1 * t2: " << t1 * t2 << std::endl;
    std::cout << "t1 - t2: " << t1 - t2 << std::endl;
    std::cout << "m * t2 : " << m * t2 << std::endl;
    system("pause");
    return 0;
}