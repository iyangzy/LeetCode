#include <iostream>
#include <vector>
using namespace std;
// 还是122的变体
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int have = INT32_MIN, not_have = 0;
    for (int i = 0; i < n; i++)
    {
        int t = not_have;
        not_have = max(not_have, have + prices[i]);// 按理说在买入和卖出时候减掉手续费都是可以的，但是因为这里hava的初始化时int的最小值，再减掉fee会溢出，可以在最小值的基础上再加上fee，避免减掉它是溢出
        have = max(have, t - prices[i] - fee);
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
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2) << endl;
    return 0;
}