#include <iostream>

class numbered
{
public:
    numbered()
    {
        mysn = unique_int++;
    }
    numbered(const numbered& n)
    {
        mysn = unique_int++;
    }
    int mysn;
    static int unique_int;
};

int numbered::unique_int = 1;

void f(numbered& s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    system("pause");
    return 0;
}