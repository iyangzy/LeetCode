#include <iostream>
#include <vector>
using namespace std;
// 书上的解法，用结果数组模拟矩阵并分区
vector<int> constructArr(vector<int> &a)
{
    if (a.size() < 2)
    {
        return {};
    }
    vector<int> b(a.size());
    b[0] = 1;
    for (int i = 1; i < a.size(); i++)
    {
        b[i] = b[i - 1] * a[i - 1];
    }
    int t = 1;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        t *= a[i + 1];
        b[i] *= t;
    }
    return b;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 0};
    vector<int> res = constructArr(v);
    for (vector<int>::iterator iter = res.begin(); iter < res.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}