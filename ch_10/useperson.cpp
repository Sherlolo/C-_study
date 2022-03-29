#include <iostream>
#include "person.h"
#include <string>
#include <cstring>

using namespace std;

int main()
{
    Person one;
    Person two{"Smthecraft"};
    Person three{"Dimwiddy", "Sam"};
    Person all[3] = {one, two, three};

    for(int i = 0; i < 3; i++)
    {
        cout << "the " << i + 1 << "person\n";
        all[i].Show();
        all[i].FormalShow();
    }
    system("pause");
    return 0;
}