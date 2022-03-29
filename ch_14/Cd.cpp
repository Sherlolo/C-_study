#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd()
{
    std::strncpy(performers, "Null perform", 50);
    performers[49] = '\0';
    std::strncpy(label, "Null label", 20);
    label[20] = '\0';
    selections = -1;
    playtime = -1;
}

Cd::Cd(char* s1, char* s2, int n, double x)
{
    std::strncpy(performers, s1, 50);
    performers[49] = '\0';
    std::strncpy(label, s2, 20);
    label[20] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    std::strncpy(performers, d.performers, 50);
    performers[49] = '\0';
    std::strncpy(label, d.label, 20);
    label[20] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}

Cd::~Cd()
{

}

void Cd::Report() const
{
    std::cout << "performers: " << performers << std::endl;
    std::cout << "label: " << label << std::endl;
    std::cout << "selection: " << selections << std::endl;
    std::cout << "playtime: " << playtime << std::endl;
    return;
}

Cd& Cd::operator=(const Cd& d)
{
    if(this == &d)
        return *this;
    std::strncpy(performers, d.performers, 50);
    performers[49] = '\0';
    std::strncpy(label, d.label, 20);
    label[20] = '\0';
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}