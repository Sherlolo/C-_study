#include <iostream>
#include <string>

class Employee
{
public:
    Employee(std::string _name) : name(_name)
    {
        ID = unique_int++;
    }
    Employee(const Employee& Epy)
    {
        name = Epy.name;
        ID = unique_int++;
    }
    Employee& operator=(const Employee& rEpy)
    {
        if(this == &rEpy)
            return *this;
        this->name = rEpy.name;
        this->ID = rEpy.ID;
        return *this;
    }
    friend void Print(const Employee& epy);
private:
    std::string name;
    int ID;
    static int unique_int;
};

int Employee::unique_int = 1;

void Print(const Employee& epy)
{
    std::cout << epy.name << ": " << epy.ID << std::endl;
}

int main()
{
    Employee epy("sherlolo");
    Employee lt("faker");
    lt = epy;
    Print(epy);
    Print(lt);
    system("pause");
    return 0;
}