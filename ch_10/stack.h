#ifndef STACK_H_
#define STACK_H_

struct customer
{
    char fullname[40];
    double payment;
};

typedef struct customer Item;

class Stack
{
private:
    Item varibles[3];
    int top;    //top -> up + 1
public:
    Stack();
    bool Isempty() const;
    bool Isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};


#endif
