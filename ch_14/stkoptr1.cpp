#include <iostream>
#include <cstdlib>
#include "stcktp1.h"
#include <ctime>
const int Num = 10;

int main()
{
    std::srand(std::time(0));
    std::cout << "Please input stack size: ";
    int stacksize;
    std::cin >> stacksize;
    Stack<const char *> st(stacksize);
    const char * in[Num] = {
        "1: faker", "2: hello world",
        "3: shelolo", "4: homelsee",
        "5: how", "6 are you",
        "7: indian mi", "8: fans",
        "9: baby", "10: sweet love"
    };
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while(processed < Num)
    {
        if(st.isempty())
            st.push(in[nextin++]);
        else if(st.isfull())
            st.pop(out[processed++]);
        else if(std::rand() % 2 && nextin < Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }

    for(int i = 0; i < Num; ++i)
    {
        std::cout << out[i] << std::endl;
    }

    std::cout << "Bybe\n";
    return 0;
}