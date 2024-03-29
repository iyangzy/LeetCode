#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
//原地置换
//如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，所以思路是重头扫描数组，遇到下标为i的数字如果不是i的话，（假设为m),那么我们就拿与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回ture
int findRepeatNumber(vector<int>& nums) 
{
    int t;
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i]!=i)
        {
            if(nums[i]==nums[nums[i]])
            {
                return nums[i];
            }
            t = nums[i];
            nums[i]=nums[t];
            nums[t]=t;
            //不使用中间变量，可以用swap函数
            // swap(nums[i],nums[nums[i]]);
        }
        
    }
    return -1;
}
//利用sort函数排序，sort排序vector的方式注意下
// int findRepeatNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for (int i = 0; i < nums.size()-1; i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
int main()
{
    int num[7] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> t(num,num+7);
    cout<<findRepeatNumber(t);
    return 0;
}