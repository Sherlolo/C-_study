#include <iostream>
#include <algorithm>
#include <vector>

class Isqual
{
public:
    Isqual(int v = 0) : value(v) {}
    bool operator()(int rhs) const
    {
        return value == rhs;
    }
private:
    int value;
};

int main()
{
    std::vector<int> vec{1, 2, 3, 3, 4, 5, 6};
    std::replace_if(vec.begin(), vec.end(), Isqual(3), 5);
    for(int i : vec) std::cout << i << std::endl;
    system("pause");
    return 0;
}