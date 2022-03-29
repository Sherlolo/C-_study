#ifndef BANK_H_
#define BANK_H_
#include <string>

class BankAccount
{
private:
    std::string name;
    std::string acctnum;
    double balance;
public:
    BankAccount(const std::string & client, const std::string & num, double val = 0.0);
    void show(void) const;
    void deposit(const double cash);
    void withdraw(const double cash);
};

#endif