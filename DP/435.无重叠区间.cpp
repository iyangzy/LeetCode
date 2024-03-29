#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int end = intervals[0][1], count = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= end)
        {
            end = intervals[i][1];
            count++;
        }
    }
    return intervals.size() - count;
}
int main()
{
    vector<vector<int>> intvs = {{0,2},{1,3},{2,4},{3,5},{4,6}};
    cout << eraseOverlapIntervals(intvs) << endl;
    return 0;
}