#include "sales.h"
#include <iostream>

using namespace std;
namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        if(n < 4)
        {
            for(int i = 0; i < n; i++)
            {
                s.sales[i] = ar[i];
            }
            for(int j = n; j < 4; j++)
            {
                s.sales[j] = 0;
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                s.sales[i] = ar[i];
            }
        }
        s.average = (s.sales[0] + s.sales[1] + s.sales[2] + s.sales[3]) / 4;
        double max = 0.0;
        double min = 65535.0;
        for(int i = 0; i < 4; i++)
        {
            if(s.sales[i] > max)
                max = s.sales[i];
            if(s.sales[i] < min)
                min = s.sales[i];
        }
        s.max = max;
        s.min = min;
    }

    void setSales(Sales & s)
    {
        cout << "please input 4 quarters for sales \n";
        for(int i = 0; i < 4; i++)
        {
            cout << "please input the " << i << "sale:\n";
            cin >> s.sales[i];
        }
         s.average = (s.sales[0] + s.sales[1] + s.sales[2] + s.sales[3]) / 4;
        double max = 0.0;
        double min = 65535.0;
        for(int i = 0; i < 4; i++)
        {
            if(s.sales[i] > max)
                max = s.sales[i];
            if(s.sales[i] < min)
                min = s.sales[i];
        }
        s.max = max;
        s.min = min;
    }

    void showSales(const Sales & s)
    {
        cout << "sales:\n";
        for(int i = 0; i < 4; i++)
        {
            cout << "sale " << i << " : " << s.sales[i];
        }
        cout << "average: " << s.average << endl;
        cout << "max: " << s.max << endl;
        cout << "min: " << s.min << endl;
    }
}