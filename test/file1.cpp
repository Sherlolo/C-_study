#include <iostream>
#include "coordin.h"

using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter x and y valuese ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}