#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int slow = 0, fast = 0, n = nums.size();
    while (fast < n)
    {
        if (nums[slow] != nums[fast])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    while (fast > slow + 1)
    {
        nums.pop_back();
        fast--;
    }
    return slow + 1;
}
int main()
{
    vector<int> nums = {};
    cout << removeDuplicates(nums) << endl;
    for (auto num : nums)
    {
        cout << num << "->";
    }
    return 0;
}