#include "wine.h"
#include <iostream>
#include <string>

template <typename T1, typename T2>
void Pair<T1, T2>::Set(const T1& yr, const T2& bt)
{
    year = yr;
    bottles = bt;
}

template <typename T1, typename T2>
int Pair<T1, T2>::Sum() const
{
    return bottles.sum();
}

template <typename T1, typename T2>
void Pair<T1, T2>::Show(int y) const
{
    for(int i = 0; i < y; ++i)
    {
        std::cout << "year: " << year[i] << "  bottles: " << bottles[i] << std::endl;
    } 
}


Wine::Wine(const char* l, int y)
{
    wine_name = l;
    year_bottle.Set(ArrayInt(y), ArrayInt(y));
    year = y;
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
    wine_name = l;
    year_bottle.Set(ArrayInt(yr, y), ArrayInt(bot, y));
    year = y;
}

Wine::~Wine()
{

}

void Wine::GetBottles()
{
    ArrayInt yr(year);
    ArrayInt bt(year);

    std::cout << "Enter " << wine_name;
    std::cout << " data for " << year << " year(s)" << std::endl;
    for(int i = 0; i < year; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> yr[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> bt[i];
    }
    year_bottle.Set(yr, bt);
    return;
}

std::string& Wine::Label()
{
    return wine_name;
}

int Wine::Sum() const
{
    return year_bottle.Sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << wine_name << std::endl;
    std::cout << "year bottles " << std::endl;
    year_bottle.Show(year);
}