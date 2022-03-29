#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 2;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for(int i = 0; i < CLIENTS; ++i)
    {
        cout << "Enter clents's name\n";
        getline(cin, temp);
        cout << "Enter client's account number\n";
        cin >> tempnum;
        cout << "Enter opening balance\n";
        cin >> tempbal;
        cout << "Enter 1 for brass Account or 2 for BrassPlus Account\n";
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter 1 or 2";
        if(kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $ ";
            cin >> tmax;
            cout << "Enter the interest rate: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while(cin.get() != '\n')
            continue;
    }
    cout << endl;
    for(int i = 0; i < CLIENTS; ++i)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for(int i = 0; i < CLIENTS; ++i)
    {
        delete p_clients[i];
        cout << endl;
    }
    cout << "Done\n";
    system("pause");
    return 0;
}