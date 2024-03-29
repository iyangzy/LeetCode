#include <iostream>
#include <vector>
using namespace std;
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> dp(amount+1);
    dp[0] = 1;
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if(j-coins[i-1]>=0)
            {
                dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }
    }
    return dp[amount];
}
//原始二维DP
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (j - coins[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << change(5, coins) << endl;
    return 0;
}