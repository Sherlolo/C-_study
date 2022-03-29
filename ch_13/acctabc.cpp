#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if(amt < 0)
        cout << "Negative deposit not allowed" << endl;
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, std::ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout << "Withdraw must be positive" << endl;
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdraw amount of $" << amt << " exceeds your balance" << endl;
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $ " << Balance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double m1, double r) : AcctABC(s, an, bal)
{
    maxloan = m1;
    oweBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double m1, double r) : AcctABC(ba)
{
    maxloan = m1;
    oweBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $ " << Balance() << endl;
    cout << "Maximu loan: $ " << maxloan << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout << "owesBank: " << oweBank << endl;
    Restore(f); 
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal = Balance();
    if(amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxloan - oweBank)
    {
        double advance = amt - bal;
        oweBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Creadit limit exceeded \n";
    Restore(f);
} 

