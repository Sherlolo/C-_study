#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
    vector<int> a = {1,2,5,4,3};
    list<int> b = {1, 2, 3, 4, 5};
    bool flag = equal(a.cbegin(), a.cend(), b.cbegin());
    int sum = accumulate(a.cbegin(), a.cend(), 0);
    stable_sort(a.begin(), a.end(), [](const int var1, const int var2){return var1 < var2;});
    cout << (flag ? "yes" : "no") << endl;
    cout << "sum: " << sum << endl;

    for(auto var : a)
    {
        cout << var << endl;
    }

    system("pause");
    return 0;
}