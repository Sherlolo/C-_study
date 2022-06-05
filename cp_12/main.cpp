#include <iostream>
#include <string>
#include <fstream>
#include "TextQuery.cpp"

using namespace std;

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
        printf("end\n");
    }
}

int main()
{
    ifstream ifs("books.txt");
    runQueries(ifs);
    return 0;
}