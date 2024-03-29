#include <iostream>
#include <vector>
using namespace std;
// 空间优化，因为k==2比较好列举
int maxProfit(vector<int> &prices)
{
    int dp_i10 = 0, dp_i11 = INT32_MIN;
    int dp_i20 = 0, dp_i21 = INT32_MIN;
    for (int price : prices) {
        dp_i20 = max(dp_i20, dp_i21 + price);
        dp_i21 = max(dp_i21, dp_i10 - price);
        dp_i10 = max(dp_i10, dp_i11 + price);
        dp_i11 = max(dp_i11, -price);
    }
    return dp_i20;
}
// 原始dp
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size(), max_k = 2;
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2)));
//     for (int i = 0; i < n; i++)
//     {
//         for (int k = max_k; k > 0; k--)
//         {
//             if (i == 0)
//             {
//                 dp[i][k][0] = 0;
//                 dp[i][k][1] = -prices[i];
//                 continue;
//             }
//             dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
//             dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
//         }
//     }
//     return dp[n-1][max_k][0];
// }
int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << maxProfit(prices) << endl;
    return 0;
}