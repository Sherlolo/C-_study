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
    Time(const int h,const int m = 0);
    void AddMin(const int m);
    void AddHr(const int h);
    void Reset(const int h = 0, const int m = 0);
    void update() 
    {
        long mins = hours*60 + minutes;
        minutes = (mins + 60) % 60;
        hours = ((mins + 24 * 60) / 60) % 24;
    }
    friend Time operator+(const Time & t1, const Time & t2);
    friend Time operator-(const Time & t1, const Time & t2);
    friend Time operator*(const Time & t1, const Time & t2);
    friend Time operator*(double m, const Time & t);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};
#endif