#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
void shuffle(vector<int> &nums)
{
    int n = nums.size();
    srand((int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        // 从 i 到最后随机选一个元素
        int r = i + (rand() % (n - i));
    }
}
int partition(vector<int> &nums, int lo, int hi)
{
    if (lo == hi)
    {
        return lo;
    }

    int pivot = nums[lo];
    int i = lo, j = hi + 1;// 在while里先做减减
    while (true)
    {
        while (nums[++i] < pivot)
        {
            if (i == hi)
            {
                break;
            }
        }
        while (nums[--j] > pivot)
        {
            if (j == lo)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[lo], nums[j]);
    return j;
}
int findKthLargest(vector<int> &nums, int k)
{
    shuffle(nums);
    int lo = 0, hi = nums.size() - 1;
    k = hi + 1 - k;
    while (lo <= hi)
    {
        int p = partition(nums, lo, hi);
        if (p > k)
        {
            hi = p - 1;
        }
        else if (p < k)
        {
            lo = p + 1;
        }
        else
        {
            return nums[p];
        }
    }
    return -1;
}
// 二叉堆
// int findKthLargest(vector<int> &nums, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> heap;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         heap.push(nums[i]);
//         if (heap.size() > k)
//         {
//             heap.pop();
//         }
//     }
//     return heap.top();
// }
int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(nums, 4) << endl;
    return 0;
}