#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    int step = 0, far = 0, pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        far = max(far, nums[i] + i);
        if (pre == i)
        {
            step++;
            pre = far;
        }
        if (pre >= n - 1)
        {
            break;
        }
    }
    return step;
}
int main()
{
    vector<int> nums = {2,3,0,1,4};
    cout << jump(nums) << endl;
    return 0;
}