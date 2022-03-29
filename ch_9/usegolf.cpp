#include <iostream>
#include "golf.h"

const int N = 4;

void print(golf name[], int len)
{
    for(int i = 0; i < len; i++)
    {
        showgolf(name[i]);
    }
    using std::cout;
    cout << "show over\n";
}

int main()
{
    golf name[N];
    for(int i = 0; i < N; i++)
    {
        if(i == 0)
        {
            setgolf(name[i], "sherlolo", 20);
        }
        else if(i == 1)
        {
            setgolf(name[i], "faker", 12);
        }
        else
        {
            setgolf(name[i]);
        }
    }
    print(name, N);
    handicap(name[0], 2);
    handicap(name[0], 1);
    print(name, N);
    return 0;
}