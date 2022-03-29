#include <iostream>
#include "stack.h"
using namespace std;

Item input_item();

int main()
{
    Stack stack;
    char flag;
    double all_payment = 0.0;
    while(1)
    {
        cout << "please chose A, D, Q:\n";
        cin >> flag;
        cin.get();
        switch(flag)
        {
            case 'a':
            case 'A':
            {
                Item temp = input_item();
                stack.push(temp);
                break;
            }
            case 'd':
            case 'D':
            {
                if (stack.Isempty())
                {
                    cout << "stack already empty\n";
                    break;
                }
                Item temp;
                stack.pop(temp);
                all_payment += temp.payment;
                break;
            }
            case 'q':
            case 'Q':
            {
                cout << "the payment is " << all_payment;
                return 0;
            }
            default:
                break;
        }
    }
}

Item input_item()
{
    Item result;
    cout << "please input fullname: ";
    cin.getline(result.fullname, 40);
    cout << "please input payment: ";
    cin >> result.payment;
    return result;
}