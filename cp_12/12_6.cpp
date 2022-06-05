#include <iostream>
#include <vector>

using std::vector;

vector<int>* alloc_vector()
{
    return new vector<int>();
}

void assign_vector(vector<int>* p)
{
    int i;
    while(std::cin >> i)
    {
        p->push_back(i);
    }
}

void print_vector(vector<int>* p)
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
    delete vec;
    system("pause");
}