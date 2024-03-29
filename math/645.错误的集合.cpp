#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int> &nums)
{
    int n = nums.size();
    int dup = -1;
    for (int i = 0; i < n; i++)
    {
        int t = abs(nums[i]) - 1;
        if (nums[t] < 0)
        {
            dup = t + 1;
        }
        else
        {
            nums[t] *= -1;
        }
    }

    int mis = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            mis = i + 1;
        }
    }
    return {dup, mis};
}
int main()
{
    vector<int> nums = {2, 2};
    vector<int> res = findErrorNums(nums);
    for (auto num : res)
    {
        cout << num << "->";
    }
    return 0;
}