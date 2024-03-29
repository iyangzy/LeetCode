#include <iostream>
#include <vector>
using namespace std;
// 状态压缩
bool canPartition(vector<int> &nums)
{
    if (nums.empty())
    {
        return false;
    }

    int sum = 0;
    for (auto num : nums)
    {
        sum += num;
    }
    if (sum & 1)
    {
        return false;
    }
    sum /= 2;

    int n = nums.size();
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= sum; j++)
    //     {
    //         if (j >= nums[i - 1])
    //         {
    //             dp[j] = dp[j - nums[i - 1]] || dp[j];
    //         }
    //     }
    // }
    // 要反向
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j >= nums[i - 1])
            {
                dp[j] = dp[j - nums[i - 1]] || dp[j];
            }
        }
    }
    return dp[sum];
}
// 原始DP
// bool canPartition(vector<int> &nums)
// {
//     if (nums.empty())
//     {
//         return false;
//     }

//     int sum = 0;
//     for (auto num : nums)
//     {
//         sum += num;
//     }
//     if (sum & 1)
//     {
//         return false;
//     }
//     sum /= 2;

//     int n = nums.size();
//     vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = true;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//             if (j >= nums[i - 1])
//             {
//                 dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
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