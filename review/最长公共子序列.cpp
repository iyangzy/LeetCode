#include <iostream>
#include <vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2)
{
    int t1 = text1.size(), t2 = text2.size();
    vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));
    for (int i = 1; i <= t1; i++)
    {
        for (int j = 1; j <= t2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[t1][t2];
}
int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}