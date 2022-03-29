#include <iostream>
#include "classic.h"

void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Captiol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia", "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    std::cout << "Using object directly:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    std::cout << "Calling a function with a Cd reference argument \n";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}


void Bravo(const Cd& disk)
{
    disk.Report();
}


