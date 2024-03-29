#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int far = 0;
    for (int i = 0; i < n - 1; i++)
    {
        far = max(far, nums[i] + i);
        if (far <= i)
            return false;
    }
    return far >= n - 1;
}
int main()
{
    vector<int> nums = {0, 2, 3};
    cout << canJump(nums) << endl;
    return 0;
}