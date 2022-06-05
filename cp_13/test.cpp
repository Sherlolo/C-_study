#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(){}
	Person(const Person& p)
	{
		cout << "Copy Constructor" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Assign" << endl;
		return *this;
	}

private:
	int age;
	string name;
};


int main()
{
	Person p;
	Person p1 = p;    
	Person p2;
	p2 = p;           
	std::getchar();
	return 0;
}
