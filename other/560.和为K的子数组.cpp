#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 前缀和优化
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x : nums)
    {
        pre += x;
        if (mp.find(pre - k) != mp.end())
        {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}
// 前缀和数组的简单应用
// int subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     vector<int> pre(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         pre[i + 1] = pre[i] + nums[i];
//     }

//     int res = 0;
//     for (int i = 0; i < n + 1; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (pre[i] - pre[j] == k)
//             {
//                 res++;
//             }
//         }
//     }
//     return res;
// }
int main()
{
    vector<int> nums = {1, 1, 1};
    cout << subarraySum(nums, 1) << endl;
    return 0;
}