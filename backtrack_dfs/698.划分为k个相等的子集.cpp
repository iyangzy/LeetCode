#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 这个解法最开始超时，加一个降序排序和去重就AC了
bool backtrack(int k, int bucket, vector<int> &nums, int index, vector<bool> &used, int target)
{
    if (k == 0)
    {
        return true;
    }
    if (bucket == target)
    {
        return backtrack(k - 1, 0, nums, 0, used, target);
    }
    if (index >= nums.size())
    {
        return false;
    }

    for (int i = index; i < nums.size(); i++)
    {
        // 去重，相邻元素必须从左往右被使用
        if (used[i] || (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]))
        {
            continue;
        }
        if (bucket + nums[i] > target)
        {
            continue;
        }

        bucket += nums[i];
        used[i] = true;
        if (backtrack(k, bucket, nums, i + 1, used, target))
        {
            return true;
        }
        bucket -= nums[i];
        used[i] = false;
    }
    return false;
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
    {
        return false;
    }
    int target = 0;
    vector<bool> used(n, false);
    for (auto i : nums)
    {
        target += i;
    }
    if (target % k != 0)
    {
        return false;
    }

    target /= k;

    sort(nums.begin(), nums.end(), greater<int>()); // 优化，降序排序，注意写法
    return backtrack(k, 0, nums, 0, used, target);
}
int main()
{
    vector<int> nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3};
    cout << canPartitionKSubsets(nums, 8) << endl;
    return 0;
}