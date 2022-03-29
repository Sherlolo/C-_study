#include <iostream>
#include "golf.h"
#include <string>
#include <cstring>

void setgolf(golf & g, const char * name, int hc)
{   
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using std::cout;
    using std::cin;
    cout << "please input fullname\n";
    cin >> g.fullname;
    if(strcmp(g.fullname, "") == 0)
    {
        cout << "cin error\n";
        return 0;
    }
    cout << "please input handicap\n";
    cin >> g.handicap;
    cin.get();
    return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;
    using std::endl;
    cout << "the full name: " << g.fullname << " the handicap: " << g.handicap << endl;
}