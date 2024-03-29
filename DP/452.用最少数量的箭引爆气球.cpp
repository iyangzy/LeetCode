#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() == 0)
    {
        return 0;
    }
    sort(points.begin(), points.end(), cmp);
    int end = points[0][1], count = 1;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > end)
        {
            end = points[i][1];
            count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> intvs = {{2, 3}, {2, 3}};
    cout << findMinArrowShots(intvs) << endl;
    return 0;
}