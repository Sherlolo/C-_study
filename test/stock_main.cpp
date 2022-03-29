#include <iostream>
#include "stock00.h"

int main()
{
    Stock the_cat;
    the_cat.acquire("NanoSmart", 20, 12.50);
    the_cat.show();

    the_cat.buy(15,18.125);
    the_cat.show();

    the_cat.sell(400, 20.00);
    the_cat.show();

    the_cat.buy(300000, 40.125);
    the_cat.show();

    the_cat.buy(3000000, 0.125);
    the_cat.show();
    system("pause");
    return 0;
}