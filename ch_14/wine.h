#ifndef WINE_H_
#define WINE_H_
#include <string>
#include <valarray>
#include <iostream>
template <typename T1, typename T2>
class Pair
{
private:
    T1 year;
    T2 bottles;
public:
    Pair() {}
    Pair(const T1& yr, const T2& bt) : year(yr), bottles(bt) {}
    void Set(const T1& yr, const T2& bt);
    int Sum() const;
    void Show(int y) const; 
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    std::string wine_name;
    PairArray year_bottle;
    int year; //个数
public:
    Wine(const char* l, int y);
    Wine(const char* l, int y, const int yr[], const int bot[]);
    ~Wine();
    void GetBottles();
    std::string& Label();
    int Sum() const;
    void Show() const;
};

#endif