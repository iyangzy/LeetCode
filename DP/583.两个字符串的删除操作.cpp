#include <iostream>
#include <vector>
using namespace std;
// 未优化的lcs
int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
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
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int minDistance(string word1, string word2)
{
    int m = word1.length(), n = word2.length();
    int lcsLength = lcs(word1, word2);
    return m + n - lcsLength * 2;
}
int main()
{
    string t1 = "sea", t2 = "eat";
    cout << minDistance(t1, t2) << endl;
    return 0;
}