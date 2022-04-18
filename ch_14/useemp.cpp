#include <iostream>
#include "emp.h"
using namespace std;

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    cout << "\nShowAll\n";
    em.ShowAll();
    cout << endl;

    mananger ma("Amorphia", "Sprindragon", "Nuancer", 5);
    cout << ma << endl;
    cout << "\nShowAll\n";
    ma.ShowAll();
    cout << endl;

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    cout << "\nShowAll\n";
    fi.ShowAll();
    cout << endl;

    highfink hf(ma, "Curly Kew");
    cout << "\nShowAll\n";
    hf.ShowAll();
    cout << endl;
    cout << "Press a key for next phase:\n";
    cin.get();

    highfink hf2;
    hf2.SetAll();

    cout << "Using an ABS_emp * pointer:\n";
    ABS_emp* tri[4] = {&em, &fi, &hf, &hf2};

    for(int i = 0; i < 4; ++i)
    {
        tri[i]->ShowAll();
    }

    return 0;
}
