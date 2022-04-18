#include <iostream>
#include "emp.h"
using std::cin;

void ABS_emp::ShowAll() const
{
    std::cout << "The full name: " << fname << " " << lname << std::endl;
    std::cout << "job: " << job << std::endl;
    return;
}

void ABS_emp::SetAll()
{
    std::cout << "Enter fname and lname: ";
    std::getline(std::cin, fname);
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

ABS_emp::~ABS_emp()
{

}

std::ostream& operator<<(std::ostream& os, const ABS_emp& e)
{
    os << "The full name: " << e.fname << " " << e.lname << std::endl;
    os  << "job: " << e.job << std::endl;
    return os;
}


void employee::ShowAll() const
{
    ABS_emp::ShowAll();
}

void employee::SetAll()
{
    ABS_emp::SetAll();
}

void mananger::ShowAll() const
{
    ABS_emp::ShowAll();
    std::cout << "The inchargeof is " << inchargeof << std::endl;
}


void mananger::SetAll()
{
    ABS_emp::SetAll();
    std::cout << "please input inchargeof: ";
    std::cin >> inchargeof;
    while(cin.get() != '\n')
    {
        continue;
    }
}


void fink::ShowAll() const
{
    ABS_emp::ShowAll();
    std::cout << "report: " << report << std::endl;
}

void fink::SetAll()
{
    ABS_emp::SetAll();
    std::cout << "please input report: ";
    std::getline(std::cin, report);
    while(cin.get() != '\n')
    {
        continue;
    }
}

void highfink::ShowAll() const
{
    ABS_emp::ShowAll();
    std::cout << "the inchargeof: " << InChargeOf() << std::endl;
    std::cout << "the report: " << Report() << std::endl;
}

void highfink::SetAll()
{
    ABS_emp::SetAll();
    std::cout << "please input inchargeof: ";
    std::cin >> InChargeOf();
    while(cin.get() != '\n')
    {
        continue;
    }

    std::cout << "please input report: ";
    std::getline(std::cin, Report());
}