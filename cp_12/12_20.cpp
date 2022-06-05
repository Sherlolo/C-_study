#include <iostream>
#include <fstream>
//#include "12_19.h"
#include "strblob.h"

int main()
{
    using namespace std;
    ifstream ifs("books.txt");
    StrBlob sb;
    string s;
    while(getline(ifs, s))
    {
        sb.push_back(s);
    }
    for(StrBlobPtr sbptr = sb.begin(); sbptr != sb.end(); sbptr.incr())
    {
        cout << sbptr.deref() << endl;
    }
    system("pause");
    return 0;
}