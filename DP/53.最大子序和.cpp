#include <iostream>
#include <vector>
using namespace std;
// int maxSubArray(vector<int> &nums)
// {
//     if (nums.size() == 1)
//     {
//         return nums[0];
//     }
//     int n = nums.size();
//     vector<int> dp(n);
//     dp[0] = nums[0];
//     int res = dp[0];
//     for (int i = 1; i < n; i++)
//     {
//         dp[i] = max(nums[i], nums[i] + dp[i - 1]);
//         res = max(res,dp[i]);
//     }
//     return res;
// }
// 状态压缩
// int maxSubArray(vector<int> &nums)
// {
//     if (nums.size() == 1)
//     {
//         return nums[0];
//     }
//     int pre,cur,res;
//     pre = nums[0];
//     res = pre;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         cur = max(nums[i],nums[i]+pre);
//         res = max(res,cur);
//         pre = cur;
//     }
//     return res;
// }
// 还可以继续压缩
int maxSubArray(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int pre,res;
    pre = nums[0];
    res = pre;
    for (int i = 1; i < nums.size(); i++)
    {
        pre = max(nums[i],nums[i]+pre);
        res = max(res,pre);
    }
    return res;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}