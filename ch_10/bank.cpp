#include <iostream>
#include "bank.h"

BankAccount::BankAccount(const std::string & client, const std::string & num, double val)
{
    name = client;
    acctnum = num;
    balance = val;
}

void BankAccount::show(void) const
{
    std::cout << "The name: " << name << std::endl;
    std::cout << "The account number: " << acctnum << std::endl;
    std::cout << "The balance: " << balance << std::endl;
}

void BankAccount::deposit(const double cash)
{
    if(cash > 0)
    {
        balance += cash;
        std::cout << "$" << cash << " cash added\n";     
    }
    else
    {
        std::cout << "input error\n";
    }
}

void BankAccount::withdraw(const double cash)
{
    if(cash > 0)
    {
        balance -= cash;
        std::cout << "$" << cash << " cash withdrawed\n";
    }
    else
    {
        std::cout << "input error";
    }
}

