#include <iostream>
#include <vector>
using namespace std;
// 在122的基础上做一点修改即可
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
// 解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int have = INT32_MIN, not_have = 0;
    int not_have_pre = 0;
    for (int i = 0; i < n; i++)
    {
        int t = not_have;
        not_have = max(not_have, have + prices[i]);
        have = max(have, not_have_pre - prices[i]);
        not_have_pre = t;
    }
    return not_have;
}
int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}