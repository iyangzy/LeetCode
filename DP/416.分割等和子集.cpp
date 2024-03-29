#include <iostream>
#include <vector>
using namespace std;
// 原始
// bool canPartition(vector<int> &nums)
// {
//     int sum = 0;
//     for (int num : nums)
//     {
//         sum += num;
//     }
//     if (sum % 2)
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
//             if (nums[i - 1] > j)
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]]; // 注意两个或的区别：区别是||只要满足第一个条件,后面的条件就不再判断,而|要对所有的条件进行判断
//             }
//         }
//     }
//     return dp[n][sum];
// }
// 状态压缩
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    if (sum % 2)
    {
        return false;
    }
    sum /= 2;
    int n = nums.size();
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0; j--) // 状态压缩时一定要注意会不会覆盖上一次循环的结果
        {
            if (nums[i - 1] <= j)
            {

                dp[j] = dp[j] || dp[j - nums[i - 1]]; // 注意两个或的区别
            }
        }
    }
    return dp[sum];
}
int main()
{
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << endl;
    return 0;
}