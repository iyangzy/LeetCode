#include <iostream>
#include <vector>
using namespace std;
int maxProfitInf(vector<int> &prices)
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

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
    if (k > n / 2)
    {
        //此时k失效，相当于k为无穷，与122题同解
        return maxProfitInf(prices);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j > 0; j--)
        {
            if (i == 0)
            {
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
                continue;
            }
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][k][0];
}
int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, prices) << endl;
    return 0;
}