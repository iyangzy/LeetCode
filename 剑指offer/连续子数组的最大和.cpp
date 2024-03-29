#include <iostream>
#include <vector>
using namespace std;
// 循环，也可以勉强叫DP
int maxSubArray(vector<int> &nums)
{
    int currValue = 0;
    int maxValue = -101;
    for (int i = 0; i < nums.size(); i++)
    {
        if (currValue < 0)
        {
            currValue = nums[i];
        }
        else
        {
            currValue += nums[i];
        }
        if (currValue > maxValue)
        {
            maxValue = currValue;
        }
    }
    return maxValue;
}
int main()
{
    vector<int> v = {-2};
    cout << maxSubArray(v) << endl;
    return 0;
}