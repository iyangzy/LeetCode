#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 这个排序方法必须是静态的
static bool comp(const vector<int> &a, const vector<int> &b)
{
    if(a[0]!=b[0])
    {
        return a[0] < b[0];
    }
    else
    {
        return a[1] > b[1];
    }
}
// LIS最长递增子序列的模板，稍微改动一下
int LIS(vector<vector<int>> nums)
{
    int p = 0, n = nums.size();
    vector<int> top(n);
    for (int i = 0; i < n; i++)
    {
        int poker = nums[i][1];
        int left = 0, right = p;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (top[mid] >= poker)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left == p)
        {
            p++;
        }
        top[left] = poker;
    }
    return p;
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    if (envelopes.empty())
    {
        return 0;
    }
    int len = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);
    for (int i = 0; i < envelopes.size(); i++)
    {
        cout<<envelopes[i][0]<<','<<envelopes[i][1]<<"->";
    }
    cout<<endl;
    return LIS(envelopes);
}
int main()
{
    vector<vector<int>> env = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(env) << endl;
    return 0;
}