#include <iostream>
#include <vector>
using namespace std;
// 自底向上
int robRange(vector<int> &nums, int m, int n)
{
    int dp = 0, pre = 0, pre_pre = 0;
    for (int i = n; i >= m; i--)
    {
        dp = max(pre, nums[i] + pre_pre);
        pre_pre = pre;
        pre = dp;
    }
    return dp;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
}
int main()
{
    vector<int> nums = {2};
    cout << rob(nums) << endl;
    return 0;
}