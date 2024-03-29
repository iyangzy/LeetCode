#include <iostream>
#include <vector>
using namespace std;
// 空间优化后的DP
bool stoneGame(vector<int> &piles)
{
    int len = piles.size();
    vector<int> dp(len);
    for (int i = 0; i < len; i++)
    {
        dp[i] = piles[i];
    }
    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < len; j++)
        {
            dp[i] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
        }
    }
    return dp[len - 1] > 0;
}
// 原始dp
// bool stoneGame(vector<int> &piles)
// {
//     int len = piles.size();
//     vector<vector<int>> dp(len, vector<int>(len));
//     for (int i = 0; i < len; i++)
//     {
//         dp[i][i] = piles[i];
//     }
//     for (int i = len - 2; i >= 0; i--)
//     {
//         for (int j = i + 1; j < len; j++)
//         {
//             dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
//         }
//     }
//     return dp[0][len - 1] > 0;
// }
int main()
{
    vector<int> piles = {5, 3, 4, 5};
    cout << stoneGame(piles) << endl;
    return 0;
}