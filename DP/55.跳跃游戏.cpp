// 换个角度就是求最值：请问通过题目中的跳跃规则，最多能跳多远？如果能够越过最后一格，返回 true，否则返回 false。
#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int fartherest = 0;
    for (int i = 0; i < n - 1; i++)
    {
        fartherest = max(fartherest, i + nums[i]);
        if (fartherest <= i)
        {
            return false;
        }
    }
    return fartherest >= n - 1;
}
int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
    return 0;
}