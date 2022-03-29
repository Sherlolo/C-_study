#include <iostream>
#include "time.h"

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp; 

    std::cout << "Aida and Tosca:\n";
    std::cout << aida << "; " << tosca << std::endl;
    temp = aida + tosca;
    std::cout << "Aida + Tosca: \n";
    std::cout << temp << std::endl;
    std::cout << "Aida * 1.2 " << aida*1.2 << std::endl;
    std::cout << "tosca + 50min\n";
    tosca.AddMin(50);
    std::cout << "tosca: " << tosca << std::endl;   
    system("pause");
    return 0;
}