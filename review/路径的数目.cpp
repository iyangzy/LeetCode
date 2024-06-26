#include <iostream>
#include <vector>
using namespace std;
// 空间压缩
int uniquePaths(int m, int n)
{
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n-1];
}
// 普通dp
// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> dp(m, vector<int>(n, 1));
//     for (int i = 1; i < m; i++)
//     {
//         for (int j = 1; j < n; j++)
//         {
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     return dp[m - 1][n - 1];
// }
int main()
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}