#include <iostream>
#include <string>

using std::string;
class HasPtr
{
public:
    HasPtr(const std::string& s = string("NULL"), int a = 0) : ps(new string(s)), i(a) {}
    HasPtr(const HasPtr& hptr) : ps(new string(*hptr.ps)), i(hptr.i) {}
    HasPtr& operator=(const HasPtr& rhptr)
    {
        if(this == &rhptr)
            return *this;
        delete ps;
        ps = new string(*rhptr.ps);
        i = rhptr.i;
        return *this;
    }
    ~HasPtr()
    {
        std::cout << "DELETE\n";
        delete ps;
    }
    friend void Print(const HasPtr& hptr);
private:
    std::string *ps;
    int i;
};

void Print(const HasPtr& hptr)
{
    std::cout << *hptr.ps << " : " << hptr.i << std::endl;
}

void fun(HasPtr hptr)
{
    std::cout << "fun()" << std::endl;
}

int main()
{
    HasPtr Hptr1;
    Print(Hptr1);
    fun(Hptr1);
    system("pause");
    return 0;
}