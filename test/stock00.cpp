#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "number of shares can't be negative; " << company << " share set to 0\n";
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Numbers of shares purchased can't be negative" << "Transaction is aborted\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        std::cout << "Numbers of shares sold can't be negative" << "Transaction is aborted\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have" << "Transaction is aborted\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout   << "compant: " << company
                << " shares: " << shares << '\n'
                << " share price " << share_val 
                << " Total_worth " << total_val << '\n';
}