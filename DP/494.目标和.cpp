#include <iostream>
#include <vector>
using namespace std;
// int subSets(vector<int> &nums, int sum)
// {
//     int len = nums.size();
//     vector<vector<int>> dp(len + 1, vector<int>(sum + 1));
//     for (int i = 0; i <= len; i++)
//     {
//         dp[i][0] = 1;
//     }
//     for (int i = 1; i <= len; i++)
//     {
//         for (int j = 0; j <= sum; j++)
//         {
//             if (j >= nums[i - 1])
//             {
//                 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }
//     return dp[len][sum];
// }
// 状态压缩
int subSets(vector<int> &nums, int sum)
{
    int len = nums.size();
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        for (int j = sum; j >= 0; j--) // 这里要逆序遍历：因为要保证在计算新的 dp[j] 的时候，dp[j] 和 dp[j-nums[i-1]] 还是上一轮外层 for 循环的结果。
        {
            if (j >= nums[i - 1])
            {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
            else
            {
                dp[j] = dp[j];
            }
        }
    }
    return dp[sum];
}
int findTargetSumWays(vector<int> &nums, int S)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum < S || (sum + S) % 2 == 1)
    {
        return 0;
    }
    return subSets(nums, (S + sum) / 2);
}
int main()
{
    vector<int> v = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(v, 5) << endl;
    return 0;
}