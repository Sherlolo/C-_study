#include <iostream>

struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>
void Swap(T &a, T & b); //函数模板

template <>
void Swap<job>(job &j1, job &j2); //显式具体化

void Show(job &j);

int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    job sue = {"susan", 73000.6, 7};
    job sidney = {"sidney", 78060, 9};
    cout << "Before job swaping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "after job swaping:\n";
    Show(sue);
    Show(sidney);
    cin.get();
    return 0;
}

template <typename T>
void Swap(T &a, T & b) //函数模板
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <>
void Swap<job>(job &j1, job &j2) //显式具体化
{
    job temp;
    temp = j1;
    j1 = j2;
    j2 = temp;
    std::cout << "specialization\n";
}

void Show(job &j)
{
    using std::cout;
    using std::endl;
    cout << "name: " << j.name << endl;
    cout << "salary: " << j.salary << endl;
    cout << "floor: " << j.floor << endl;
}