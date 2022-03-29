#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(const int h, const int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    long total_minutes() const
    {
        return hours*60 + minutes;
    }
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(const double n) const;
    friend Time operator*(double m, const Time & t)
    {
        return t * m;   //inline definition
    }
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

};

#endif