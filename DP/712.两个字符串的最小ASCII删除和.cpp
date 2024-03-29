#include <iostream>
#include <vector>
using namespace std;
// 嘻嘻，我都会自己造了，虽然还是不会状态压缩
int minimumDeleteSum(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] += dp[i - 1][0] + s1[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + s2[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string t1 = "delete", t2 = "leet";
    cout << minimumDeleteSum(t1, t2) << endl;
    return 0;
}