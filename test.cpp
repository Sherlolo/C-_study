#include <iostream>
#include <string>

using std::string;
class Test
{
public:
    Test(string _a) : a(_a) 
    {
        std::cout << "Test()" << std::endl;
    }
    Test(const Test& rhs)
    {
        std::cout << "Test(Test&)" << std::endl;
        a = rhs.a;
    }
    Test& operator=(const Test& rhs)
    {
        if(this == &rhs)
            return *this;
        a = rhs.a;
        return *this;
    }
private:
    string a;
};

int main()
{
    std::cout << "a" << std::endl;
    Test a("a");
    std::cout << "b" << std::endl;
    Test b{"a"};
    std::cout << "c" << std::endl;
    Test c = "a";
    system("pause");
    return 0;
}
