#include <iostream>
#include "dma.h"
const int LEN = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA *temp[LEN];
    char label[50];
    char style[50];
    char color[40];
    char kind;
    int rating;

    cout << "Here are the process for creating 3 objects" << endl;

    for(int i = 0; i < LEN; ++i)
    {
        cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA" << endl;
        while(cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Please enter 1, 2 or 3: ";
        }
        if (kind == '1')
        {
            cout << "Please input the label: ";
            cin >> label;
            cout << "Please input the rating: ";
            cin >> rating;
            temp[i] = new baseDMA(label, rating, "baseDMA");
        }
        else if (kind == '2')
        {
            cout << "Please input the color: ";
            cin >> color;
            temp[i] = new lacksDMA(color, "lacksDMA");
        }
        else
        {
            cout << "Please input the style: ";
            cin >> style;
            temp[i] = new hasDMA(style, "hasDMA");
        }
    }

    cout << "\n the result after creating 3 objects" << endl;
    for(int i = 0; i < LEN; ++i)
    {
        temp[i]->View();
        //cout << temp[i]->show_classname();
    }

    for(int i = 0; i < LEN; ++i)
    {
        delete temp[i];
    }
    cout << "Done\n";
    return 0;
}