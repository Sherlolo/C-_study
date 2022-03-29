#include <iostream>
#include "stringbad.cpp"
using std::cout;
void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;
    {
        StringBad h1("headlin1");
        StringBad h2("headlin2");
        StringBad sports("Dollars kevils");
        cout << "h1: " << h1 << endl;
        cout << "h2: " << h2 << endl;
        cout << "sports: " << sports << endl;

        callme1(h1);
        cout << "after callme1 h1: " << h1 << endl;

        callme2(h2);
        cout << "after callme2 h2: " << h2 << endl;

        StringBad sailor = sports;
        StringBad knot;
        knot = h1;

        cout << "sailor: " << sailor << endl;
        cout << "knot: " << knot << endl;
        cout << "exit block\n";
    }
    cout << "BYBE" << endl;
    system("pause");
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "referce rsb: " << rsb << std::endl;
}

void callme2(StringBad rsb)
{
    cout << "pass value rsb: " << rsb << std::endl;
}