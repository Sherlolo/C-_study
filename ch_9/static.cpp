#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int ArSize = 10;
void strcount(const string &str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "Enter a line\n";
    getline(cin, input);
    while(cin)
    {
        strcount(input);
        if(input == "")
            break;
        cout << "Enter next line(empyt line to quit):\n";
        getline(cin, input);
    }
    cout << "Bybe" << endl;
    return 0;
}

void strcount(const string &str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\" contains ";
    count = str.size();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}