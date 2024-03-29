#include <iostream>
#include <vector>
using namespace std;
// 状态压缩
int minInsertions(string s)
{
    int n = s.length();
    vector<int> dp(n, 0);

    int t = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int pre = 0;
        for (int j = i + 1; j < n; j++)
        {
            t = dp[j];
            if (s[i] == s[j])
            {
                dp[j] = pre;
            }
            else
            {
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            }
            pre = t;
        }
    }
    return dp[n - 1];
}
// 原始DP
// int minInsertions(string s)
// {
//     int n = s.length();
//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (s[i] == s[j])
//             {
//                 dp[i][j] = dp[i + 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
//             }
//         }
//     }
//     return dp[0][n - 1];
// }
int main()
{
    cout << minInsertions("no") << endl;
    return 0;
}