#include <iostream>
#include "time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(const int h, const int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours = (hours + minutes / 60) % 24;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours = (hours + h) % 24;
}

void Time::Reset(int h, int m)
{
    hours = minutes = 0;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    long sum_minutes = total_minutes() + t.total_minutes();
    sum.hours = sum_minutes / 60;
    sum.minutes = sum_minutes % 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time sum;
    long sum_minutes = total_minutes() - t.total_minutes();
    sum.hours = sum_minutes / 60;
    sum.minutes = sum_minutes % 60;
    return sum;
}

Time Time::operator*(const double n) const
{
    Time sum;
    long sum_minutes = total_minutes() * n;
    sum.hours = sum_minutes / 60;
    sum.minutes = sum_minutes % 60;
    return sum;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes ";
    return os;
}