#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 灵活运用异或
vector<int> FindNumsAppearOnce(vector<int> &array)
{
    int ret = 0;
    for (auto i : array)
    {
        ret ^= i;
    }
    int digit = 1;
    while ((ret & digit) == 0)
    {
        digit <<= 1;
    }
    int a = 0, b = 0;
    for (auto i : array)
    {
        if ((i & digit))
        {
            a ^= i;
        }
        else
        {
            b ^= i;
        }
    }
    return a > b ? vector<int>{b, a} : vector<int>{a, b};
}
int main()
{
    vector<int> array = {1, 4, 1, 6};
    vector<int> res = FindNumsAppearOnce(array);
    for (auto i : res)
    {
        cout << i << "->";
    }
    return 0;
}