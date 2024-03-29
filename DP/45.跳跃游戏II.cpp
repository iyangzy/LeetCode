#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size(), step = 0, fartherest = 0, end = 0;
    for (int i = 0; i < n - 1; i++)
    {
        fartherest = max(fartherest,nums[i]+i);
        if (end == i)
        {
            step++;
            end = fartherest;
        }
    }
    return step;
}
int main()
{
    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << jump(nums) << endl;
    return 0;
}