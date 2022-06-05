#include <iostream>
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string& s = std::string(), int a = 0) : ps(new std::string(s)), i(a), use(new std::size_t(1)){}
    HasPtr(const HasPtr& hptr) : ps(hptr.ps), i(hptr.i), use(hptr.use)
    {
        ++*use;
    }
    HasPtr& operator=(const HasPtr& rhptr)
    {
        ++*use;
        if(this == &rhptr)
            return *this;
        ps = rhptr.ps;
        i = rhptr.i;
        use = rhptr.use;
        return *this;
    }
    ~HasPtr()
    {
        std::cout << "delete()\n";
        if(--*use == 0)
        {
            delete ps;
            delete use;
        }
    }
// private:
    std::string* ps;
    int i;
    std::size_t* use; //use flag
};


void Print(const HasPtr& hptr)
{
    std::cout << *hptr.ps << " : " << hptr.i << " : " << *(hptr.use) << std::endl;
}

void fun(HasPtr hptr)
{
    std::cout << "fun()" << std::endl;
    Print(hptr);
}

int main()
{
    HasPtr a;
    HasPtr b("sherlolo", 1);
    HasPtr c = b;
    Print(a);
    Print(b);
    fun(a);
    system("pause");
    return 0;
}