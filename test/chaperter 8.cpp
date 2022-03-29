/*
4ti
#include <iostream>
#include <cstring>
using namespace std;
struct stringy
{
    char * strs;
    int ct;
};

void set(stringy &var, const char *strs)
{
    var.ct = strlen(strs);
    var.strs = new char (var.ct + 1);
    strcpy(var.strs, strs);
}

show(const stringy &var, int n = 1)
{
    for(int i = 0; i < n; i++)
    {
        cout << var.strs << endl;
    }
}

show(const char *var, int n = 1)
{
    for(int i = 0; i < n; i++)
    {
        cout << var << endl;
    }
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    system("pause");
    return 0;
}

*/


#include <iostream>
#include <string>
#include <cstring>
#include <cctype>


using namespace std;

struct CandyBar
{
    char *name;
    double height;
    int calor;
};

void print_str(const char * strs, int flag = 0);
void print_struct(CandyBar &var, char *strs = "Mile Munch", double height = 2.85, int calor = 350);
void strs_to_captial(string &strs);

template <class T>
T MAX5(const T var[]);

template <typename T>
T MAXS(T var[], int lengths);

template <> 
const char * MAXS(const char* var[], int lengths);

// template <typename T>
// T MAXS(T var[], int lengths);
 
// template <> char * MAXS(char * var[], int lengths);


int main()
{
    int var1[5] = {1, 2, 3, 5, 1};
    double var2[5] = {7.7, 23.1, 13, 32, 66.6};
    cout << "int max: " << MAX5(var1) << endl;
    cout << "double max: " << MAX5(var2) << endl;
    system("pause");
    return 0;
}


template <typename T>
T MAXS(T var[], int lengths)
{
    T max_value = var[0];
    for(int i = 1; i < lengths; i++)
    {
        if(var[i] > max_value)
        {
            max_value = var[i];
        }

    }
    return max_value;
}

template <> char * MAXS(char* var[], int lengths)
{
    int max_length = strlen(var[0]);
    int flag = 0;
    for(int i = 1; i < lengths; i++)
    {
        int temp = strlen(var[i]);
        if(temp > max_length)
        {
            max_length = temp;
            flag = i;
        }
    }
    return var[flag];
}



template <class T>
T MAX5(const T var[])
{
    T temp = var[0];
    for(int i = 1; i < 5; i++)
    {
        if(var[i] > temp)
        {
            temp = var[i];
        }
    }
    return temp;
}

void print_str(const char * strs, int flag)
{
    static int count = 0;
    count++;
    if(flag == 0)
        cout << strs << endl;
    else
        for(int i = 0; i < count; i++)
        {
            cout << strs << endl;
        }
}


void print_struct(CandyBar &var, char *strs, double height, int calor)
{
    var.name = strs;
    var.height = height;
    var.calor = calor;
    cout << "name: " << var.name << endl;
    cout << "height " << var.height << endl;
    cout << "calor " << var.calor << endl;
}

void strs_to_captial(string &strs)
{
    for(int i = 0; strs[i]; i++)
    {
        strs[i] = toupper(strs[i]);
    }
}
