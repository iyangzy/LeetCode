#include <iostream>
#include <vector>
using namespace std;
// 还可以做状态压缩
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string t1 = "ace", t2 = "dfg";
    cout << longestCommonSubsequence(t1, t2) << endl;
    return 0;
}