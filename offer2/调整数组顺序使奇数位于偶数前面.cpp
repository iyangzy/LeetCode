#include <iostream>
#include <vector>
using namespace std;
// 这个解法还没有直接用空间换时间的性能好
vector<int> reOrderArray(vector<int> &array)
{
    int n = array.size();
    array.resize(n * 2);
    int i = 0, j = n;
    while (i < n)
    {
        if ((array[i] & 1) == 0)
        {
            array[j] = array[i];
            array.erase(array.begin() + i);
            i--;
            n--;
        }
        i++;
    }
    return {array.begin(), array.begin() + j};
}
int main()
{
    vector<int> array = {};
    vector<int> res = reOrderArray(array);
    for (auto r : res)
    {
        cout << r << "->";
    }
    return 0;
}