#include <iostream>
#include "mytime.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(const int h,const int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(const int m)
{   
    minutes += m;
    update();
}

void Time::AddHr(const int h)
{
    hours += h;
    update();
}

void Time::Reset(const int h, const int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time & t1, const Time & t2)
{
    Time result(t1.hours + t2.hours, t1.minutes + t2.minutes);
    result.update();
    return result;
}

Time operator-(const Time & t1, const Time & t2)
{   
    Time result(t1.hours - t2.hours, t1.minutes - t2.minutes);
    result.update();
    return result;
}

Time operator*(const Time & t1, const Time & t2)
{
    Time result(t1.hours * t2.hours, t1.minutes * t2.minutes);
    result.update();
    return result;
}   

Time operator*(double m, const Time & t)
{
    Time result(m * t.hours, m * t.minutes);
    result.update();
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}