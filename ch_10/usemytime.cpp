#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca:\n";
    cout << temp << endl;
    cout << "Aida * 1.16 " << aida*1.16 << endl;
    cout << "Aida.minutes + 30\n";
    aida.AddMin(30);
    cout << aida << endl;
    system("pause");
    return 0;
}