#include <iostream>
#include "move.h"

int main()
{
    Move a;
    a.showmove();
    Move b(2, 3);
    b.showmove();
    Move c;
    c = a.add(b);
    c.showmove();
    std::cout << "after reset\n";
    c.reset();
    c.showmove();
    system("pause");
    return 0;
}