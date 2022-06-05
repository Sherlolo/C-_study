#include <iostream>
#include <string>
#include "StrVec.cpp"


void Print(const StrVec& svec)
{
    for(auto begin = svec.begin(); begin != svec.end(); ++begin)
    {
        std::cout << *begin << std::endl;
    }
}

int main()
{
    StrVec svec;
    for(int i = 0; i < 3; ++i)
    {
        std::string temp;
        std::cin >> temp;
        svec.push_back(temp);
    }
    Print(svec);
    StrVec svec_move;
    svec_move = std::move(svec);
    Print(svec_move);
    system("pause");
    return 0;
}