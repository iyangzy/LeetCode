#include <iostream>
#include <vector>
using namespace std;
// 自底向上
int rob(vector<int> &nums)
{
    int n = nums.size();
    int dp = 0, pre = 0, pre_pre = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp = max(pre,nums[i]+pre_pre);
        pre_pre = pre;
        pre = dp;
    }
    return dp;
}
// 自顶向下
// vector<int> memo;
// int dp(vector<int> &nums,int start)
// {
//     if (start>=nums.size())
//     {
//         return 0;
//     }
//     if (memo[start]!=-1)
//     {
//         return memo[start];
//     }
    
//     int res = max(dp(nums,start+1),nums[start]+dp(nums,start+2));
//     memo[start] = res;
//     return res;
// }
// int rob(vector<int> &nums)
// {
//     memo.resize(nums.size(),-1);
//     return dp(nums,0);
// }
int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
    return 0;
}