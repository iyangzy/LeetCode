#include <iostream>
#include <vector>
using namespace std;
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<int> numsNew(n + 2, 1);
    for (int i = 1; i < n + 1; i++)
    {
        numsNew[i] = nums[i - 1];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = i + 2; j <= n + 1; j++)
        {
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + numsNew[i] * numsNew[k] * numsNew[j]);
            }
        }
    }
    return dp[0][n + 1];
}
int main()
{
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    return 0;
}