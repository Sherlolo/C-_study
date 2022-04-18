#include <iostream>
#include "workmi.h"

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker()
{

}

void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get() != '\n')
    {
        continue;
    }
}

void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Panache is " << panache << endl;
}

void Waiter::Get()
{
    cout << "Please input panache: ";
    cin >> panache;
    while(cin.get() != '\n')
    {
        continue;
    }
}


//Singer method

char* Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};


void Singer::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}


void Singer::Get()
{
    for(int i = 0; i < Vtypes; ++i)
    {
        printf("%d : %s \n", i, pv[i]);
    }
    cout << "Please input number to chose vocal: ";
    cin >> voice;
    while(cin.get() != '\n')
    {
        continue;
    }
}

void Singer::Data() const
{
    cout << "The voice is " << voice << endl;
    cout << "Vocal range: " << pv[voice] << endl;
}
