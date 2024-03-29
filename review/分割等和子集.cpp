#include <iostream>
#include <vector>
using namespace std;
// 状态压缩
bool canPartition(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return false;
    }

    int sum = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum /= 2;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j - nums[i] >= 0)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
    }
    return dp[sum];
}
// 原始DP
// bool canPartition(vector<int> &nums)
// {
//     if (nums.size() < 2)
//     {
//         return false;
//     }

//     int sum = 0, n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         sum += nums[i];
//     }
//     if (sum % 2 != 0)
//     {
//         return false;
//     }
//     sum /= 2;

//     vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
//     for (int i = 0; i < n + 1; i++)
//     {
//         dp[i][0] = true;
//     }

//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < sum + 1; j++)
//         {
//             if (j - nums[i - 1] < 0)
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
//             }
//         }
//     }
//     return dp[n][sum];
// }
int main()
{
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << endl;
    return 0;
}