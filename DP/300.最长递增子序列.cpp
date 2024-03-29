#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 二分查找，不太理解
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> top(n);
    int piles = 0;
    for (int i = 0; i < n; i++)
    {
        int poker = nums[i];
        int left = 0, right = piles; // right是取不到的，left是取得到的
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (top[mid] > poker)
            {
                right = mid;
            }
            else if (top[mid] < poker)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (left == piles)
        {
            piles++;
        }
        top[left] = poker;
    }
    return piles;
}
// DP
// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, 1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[j] < nums[i])
//             {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     return *max_element(dp.begin(), dp.end());
// }
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}