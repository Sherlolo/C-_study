#include <iostream>
#include "plorg.h"
#include <cstring>
#include <string>

Plorg::Plorg(const char news[], const int var)
{
    strncpy(name, news, 20);
    CI = var;
}

void Plorg::set_ci(const int var)
{
    CI = var;
}

void Plorg::show_plorg() const
{
    std::cout << "The name: " << name << " The CI: " << CI << std::endl;
}
