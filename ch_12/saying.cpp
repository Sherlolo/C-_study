#include <iostream>
#include <cstdlib>
#include "string.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;
    string name;
    cout << "Hi, what's your name?\n";
    cin >> name;
    cin.get();
    cout << name << ", please enter up to " << ArSize << "short saying <empty line to quit>" << endl;
    string sayings[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; ++i)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;
    if(total > 0)
    {
        cout << "Here are your saying\n";
        for (i = 0; i < total; ++i)
        {
            cout << sayings[i] << endl;
        }
        string * shortest = &sayings[0];
        string * first = &sayings[0];
        for(i = 1; i < total; ++i)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        cout << "shortest saying:  " << *shortest << endl;
        cout << "First alphacally: " << *first << endl;
        int choice = rand() % total;
        string * favorite = new string(sayings[choice]);
        cout << "My favorite saying: " << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Not much to say \n";
    cout << "Bye \n";
    system("pause");
    return 0;
}