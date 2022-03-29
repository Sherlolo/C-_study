#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;
Golf::Golf(const char * name, int hc)
{
    strncpy(fullname, name, 40);
    handicap = hc;
}

Golf::Golf()
{
    char temp[40];
    int hand;
    cout << "Please enter the full name of golf player: ";
    cin.getline(temp, 40);
    cout << "Please enter the handicap of golf player: ";
    cin >> hand;
    cin.ignore();
    *this = Golf(temp, hand);
}

void Golf::sethandicap(const int hc)
{
    handicap = hc;
}

void Golf::showgolf() const
{
    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}