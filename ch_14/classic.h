#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"
class Classic : public Cd
{
private:
    char main_product[20];
public:
    Classic(char* s1, char* s2, char* s3, int n, double x);
    Classic(const Classic &d);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    Classic& operator=(const Classic& d);
};

#endif