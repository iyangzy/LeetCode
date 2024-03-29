#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 摩尔投票法
int majorityElement(vector<int> &nums)
{
    int x = 0, vote = 0;
    for (int num : nums)
    {
        if (vote == 0)
        {
            x = num;
        }
        vote += num == x ? 1 : -1;
    }
    // 题设存在出现多次的数字x，若没有该假设还需在加验证
    int count = 0;
    for (int num : nums)
    {
        if (num == x)
        {
            count++;
        }
    }
    return count >= nums.size() / 2 ? x : 0;// 在目前的题设条件下该语句可以不用
    return x;
}

// 还有另一种解法
// 数组排序法： 将数组 nums 排序，数组中点的元素 一定为出现一半的数。

// 暴力循环，不牵扯算法，性能极差。。。。
// int majorityElement(vector<int> &nums)
// {
//     map<int,int> re;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (re.find(nums[i]) == re.end())
//         {
//             re[nums[i]] = 1;
//             if (nums.size() == 1)
//             {
//                 return nums[i];
//             }
//             continue;
//         }
//         if (re[nums[i]] >= nums.size()/2)
//         {
//             return nums[i];
//         }
//         else
//         {
//             re[nums[i]]++;
//         }
//     }
//     return -1;
// }
int main()
{
    vector<int> v = {2};
    cout << majorityElement(v) << endl;
    return 0;
}