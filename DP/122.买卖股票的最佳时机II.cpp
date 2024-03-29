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
        int t = not_have;
        not_have = max(not_have, have + prices[i]);
        have = max(have, t - prices[i]);
    }
    return not_have;
}
// 原始DP
// int maxProfit(vector<int> &prices)
// {
// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
//             = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])

// 我们发现数组中的 k 已经不会改变了，也就是说不需要记录 k 这个状态了：
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
// }
int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    return 0;
}