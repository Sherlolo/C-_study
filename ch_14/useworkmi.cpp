#include <iostream>
#include <cstring>
#include "workmi.h"
const int SIZE = 5;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;

    Worker * lolas[SIZE];

    int ct;
    for(ct = 0; ct < SIZE; ++ct)
    {
        char choice;
        cout << "Enter the employee Category:\n"
             << "W: waiter\n"
             << "S: singer\n"
             << "q: quit\n";
        cin >> choice;
        while(strchr("WSq", choice) == NULL)
        {
            cout << "Please enter W, S, or q: ";
            cin >> choice;
        }
        if(choice == 'q')
            break;
        switch(choice)
        {
            case 'W':
                lolas[ct] = new Waiter;
                break;
            case 'S':
                lolas[ct] = new Singer;
                break;
        }
        cout << "11\n";
        while(cin.get() != '\n')
            continue;
        cout << "22\n";
        lolas[ct]->Set();
        cout << "33\n";
    }
    cout << "\n Here is your staff \n";
    for(int i = 0; i < ct; ++i)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for(int i = 0; i < ct; ++i)
    {
        delete lolas[i];
    }
    cout << "Bybe \n";
    return 0;
}