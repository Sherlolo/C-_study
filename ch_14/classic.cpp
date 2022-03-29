#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic() : Cd()
{
    std::strncpy(main_product, "Null product", 20);
    main_product[19] = '\0';
}


Classic::Classic(char* s1, char* s2, char* s3, int n, double x) : Cd(s1, s2, n, x)
{
    std::strncpy(main_product, s3, 20);
    main_product[19] = '\0';
}

Classic::Classic(const Classic &d) : Cd(d)
{
    std::strncpy(main_product, d.main_product, 20);
    main_product[19] = '\0';
}


Classic::Classic::~Classic()
{

}

void Classic::Report() const
{
    //(const Cd&)(*this).Report();
    Cd::Report();
    std::cout << "The main_product: " << main_product << std::endl;
    return;
}

Classic& Classic::operator=(const Classic& d)
{
    if(this == &d)
        return *this;
    //(Cd)(*this) = (const Cd&)d;
    Cd::operator=(d);
    std::strncpy(main_product, d.main_product, 20);
    main_product[19] = '\0';
    return *this;
}
//私有继承 公有继承 保护继承的关系
