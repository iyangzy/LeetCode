#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}
// 按区间终点排序，贪心
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
    {
        return 0;
    }

    // sort(intervals.begin(), intervals.end(), cmp);
    sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2)
         { return v1[1] < v2[1]; });
    int n = intervals.size();
    int end = INT32_MIN, sum = 0;
    for (auto vec : intervals)
    {
        if (vec[0] >= end)
        {
            end = vec[1];
            sum++;
        }
    }
    return n - sum;
}
int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}