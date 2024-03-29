#include <iostream>
#include <vector>
using namespace std;
// 书上的解法
int maxValue(vector<vector<int>> &grid)
{
    if(grid.size()==0)
    {
        return 0;
    }
    vector<int> dp(grid[0].size());
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            int left = 0,up = 0;
            if (i>0)
            {
                up = dp[j];
            }
            if(j>0)
            {
                left = dp[j-1];
            }
            dp[j] = max(left,up) + grid[i][j];
        }
    }
    return dp[grid[0].size()-1];
}
int main()
{
    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << maxValue(v) << endl;
    return 0;
}