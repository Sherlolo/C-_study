#include <iostream>
#include <string>
#include "bank.h"

int main()
{
    using namespace std;
    string client;
    string num;
    double bal;
    cout << "please input your information for operation:\n";
    cout << "your name: ";
    getline(cin, client);
    cout << "your account number: ";
    getline(cin, num);
    cout << "your balance: ";
    cin >> bal;
    BankAccount myaccount{client, num, bal};
    myaccount.show();
    cout << "Bybe\n";
    system("pause");
    return 0;
}