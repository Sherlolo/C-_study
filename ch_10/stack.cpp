#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::Isempty() const
{
    if (top == 0)
        return true;
    else
        return false;
}

bool Stack::Isfull() const
{
    if (top == 3)
        return true;
    else
        return false;
}

bool Stack::push(const Item & item)
{
    using std::cout;
    if (Isfull())
    {
        cout << "The Stack is full\n";
        return false;
    }
    else
    {
        varibles[top++] = item;
        return true;
    }
}

bool Stack::pop(Item & item)
{
    using std::cout;
    if (Isempty())
    {
        cout << "The Stack is emtpy\n";
        return false;
    }
    else
    {
        item = varibles[--top];
        return true;
    }
}