#include <iostream>
#include <vector>
using namespace std;
// 二分查找左右边界
// 为避免重复代码，定义一个helper函数，分别查找target的右边界和“target-1”的右边界（相当于target的左边界）
int helper(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // 避免“high+low”超出int的范围
        if (nums[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int search(vector<int> &nums, int target)
{
    return helper(nums, target) - helper(nums, target - 1);
}
// 自己的写的二分查找，逻辑是找到一个等于target的位置，再向前后发散，找全所有的target，但是这是的算法效率与从头到尾遍历的效率是等价的，所以pass
// int search(vector<int> &nums, int target)
// {
//     if (nums.size() == 0)
//     {
//         return 0;
//     }

//     int low = 0, high = nums.size() - 1, count = 0, mid;
//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;
//         if (nums[mid] < target)
//         {
//             low = mid + 1;
//         }
//         if (nums[mid] > target)
//         {
//             high = mid - 1;
//         }
//         if (nums[mid] == target)
//         {
//             count++;
//             break;
//         }
//     }
//     if (count != 0)
//     {
//         for (int i = mid - 1; i >= low; i--)
//         {
//             if (nums[i] == target)
//                 count++;
//         }
//         for (int j = mid + 1; j <= high; j++)
//         {
//             if (nums[j] == target)
//                 count++;
//         }
//     }

//     return count;
// }
int main()
{
    vector<int> v = {5, 7, 7, 8, 8, 10};
    cout << search(v, 8) << endl;
    return 0;
}