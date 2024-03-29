#include <iostream>
#include <vector>
using namespace std;
// 滑动窗口
vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    int left = 1, right = 1, s = 0;
    while (left <= sum / 2)
    {
        if (s < sum)
        {
            s += right;
            right++;
        }
        else if (s > sum)
        {
            s -= left;
            left++;
        }
        else
        {
            vector<int> array;
            for (int i = left; i < right; i++)
            {
                array.push_back(i);
            }
            res.push_back(array);
            s -= left;
            left++;
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res = FindContinuousSequence(100);
    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << "->";
        }
        cout << endl;
    }
    return 0;
}