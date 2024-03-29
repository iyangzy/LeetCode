#include <iostream>
#include <vector>
using namespace std;
// int change(int amount, vector<int> &coins)
// {
//     int n = coins.size();
//     vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
//     // 初始化的时候要注意dp[0][0]是多少，避免因覆盖出错
//     for (int i = 0; i <= amount; i++)
//     {
//         dp[0][i] = 0;
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= amount; j++)
//         {
//             if (j < coins[i - 1])
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
//             }
//         }
//     }
//     return dp[n][amount];
// }
// 状态压缩
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }
    }
    return dp[amount];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << change(5, coins) << endl;
    return 0;
}