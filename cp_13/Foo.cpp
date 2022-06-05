#include <vector>
#include <iostream>
#include <algorithm>

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    std::vector<int> data;
};


Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    std::cout<< "sort() &&" << std::endl;
    return *this;
}

Foo Foo::sorted() const &
{
    std::cout << "sort() &" << std::endl;

    // Foo ret(*this);
    // return ret.sorted();     // Exercise 13.56

    // return Foo(*this).sorted();
}

int main()
{
    Foo().sorted(); //call "&&"
    Foo f;
    std::cout << "f.sorted()\n";
    f.sorted(); //call "const &"
    system("pause");
    return 0;
}