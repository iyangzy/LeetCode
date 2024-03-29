#include <iostream>
#include <vector>
using namespace std;
// 空间优化
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int have = INT32_MIN, not_have = 0;
    for (int i = 0; i < n; i++)
    {
        not_have = max(not_have,have+prices[i]);
        have = max(have,-prices[i]);
    }
    return not_have;
}
// 原始DP
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2));
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             dp[i][0] = 0;
//             dp[i][1] = -prices[i];
//             continue;
//         }

//         dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//         dp[i][1] = max(dp[i - 1][1], -prices[i]);
//     }
//     return dp[n - 1][0];
// }
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}