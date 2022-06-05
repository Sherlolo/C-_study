#include <iostream>
#include <fstream>
#include <string>
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
        Print_result(tq.query(s));
        printf("end\n");
    }
}

int main()
{
    ifstream ifs("books.txt");
    runQueries(ifs);
}