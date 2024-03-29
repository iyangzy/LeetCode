#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet;
    for (int i = 0; i < nums.size(); i++)
    {
        numSet.insert(nums[i]);
    }

    unordered_set<int>::iterator iter = numSet.begin();
    int len = 0;
    // 直接下面这么写会超时 需要优化
    // while (iter != numSet.end())
    // {
    //     int subLen = 1;
    //     int t = *iter;
    //     while (numSet.find(t+1) != numSet.end())
    //     {
    //         subLen++;
    //         t++;
    //     }
    //     len = subLen > len ? subLen : len;
    //     iter++;
    // }
    while (iter != numSet.end())
    {
        int t = *iter;
        if (numSet.find(t - 1) != numSet.end())
        {
            iter++;
            continue;
        }
        
        int subLen = 1;
        while (numSet.find(t + 1) != numSet.end())
        {
            subLen++;
            t++;
        }
        len = subLen > len ? subLen : len;
        iter++;
    }
    return len;
}
int main()
{
    vector<int> num = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(num) << endl;
    vector<int> num2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(num2) << endl;
}