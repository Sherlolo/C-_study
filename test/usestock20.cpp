#include <iostream>
#include "stock20.h"

const int STKS = 4;
int main()
{
    Stock stocks[STKS] = {
        Stock("faker", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 120, 3.25),
        Stock("Fleep", 60, 6.5)
    };
    std::cout << "Stock holdings\n";
    int st;
    for (st = 0; st < STKS; st++)
    {
        stocks[st].show();
    }
    const Stock * top = &stocks[0];
    std::cout << "\nmost valueable holding:\n";
    top->show();
    return 0;
}