#include <iostream>
#include <vector>
#include <memory>

using std::vector;

std::shared_ptr<std::vector<int>> alloc_vector()
{
    return std::make_shared<vector<int>>();
}

void assign_vector(std::shared_ptr<std::vector<int>> p)
{
    int i;
    while(std::cin >> i)
    {
        p->push_back(i);
    }
}

void print_vector(std::shared_ptr<std::vector<int>> p)
{
    for(auto item : *p)
    {
        std::cout << item << std::endl;
    }
}


int main()
{
    auto vec = alloc_vector();
    assign_vector(vec);
    print_vector(vec);
    system("pause");
}