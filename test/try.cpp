// twoswap.cpp -- specialization overrides a template
#include<iostream>
using namespace std;
template <typename T>
void Swap(T &a, T &b);

struct job {
	char name[40];
	double salary;
	int floor;
};

// explicit specialization 显示具体化
template <> void Swap<job>(job &j1, job &j2);
void Show(job &j);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "使用编译器生成的交换函数:\n";
	Swap(i, j);
	cout << "Now i, j = " << i << ", " << j << ".\n";

	job sue = {"Susan Yaffee", 73000.60, 7 };
	job sidney = {"Sidney Taffee", 78060.72, 9 };
	cout << "工作交换前:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);	// 这里使用的是非模板 void Swap(job &, jpb &)
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
	// cin.get();
	system("pause");
}

// 一般函数（非模板函数）
template <typename T>
void Swap(T &a, T &b)	// general version
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// 显示具体化
// swaps just the salary and floor fields of a job structure
template <> void Swap<job>(job &j1, job &j2)
{
	double t1;
	int t2;
	// 交换salary
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	// 交换floor
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job &j)
{
	cout << j.name << ": $" << j.salary
		<< " on floor " << j.floor << endl;
}
