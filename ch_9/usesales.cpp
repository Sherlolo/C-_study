#include <iostream>
#include "sales.h"

using namespace std;
//using namespace SALES;

int main()
{
    SALES::Sales var1;
    SALES::Sales var2;
    double arr[4] = {1, 2, 5, -1};
    SALES::setSales(var1, arr, 4);
    SALES::setSales(var2);

    cout << "Sale 1\n";
    SALES::showSales(var1);

    cout << "Sale 2\n";
    SALES::showSales(var2);
}