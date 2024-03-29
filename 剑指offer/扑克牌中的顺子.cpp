#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
bool isStraight(vector<int> &nums)
{
    if (nums.size() < 1)
    {
        return false;
    }
    sort(nums.begin(), nums.end());
    int sumZero = 0;
    int i = 0;
    for (; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            sumZero++;
            continue;
        }
        break;
    }
    int sumGap = 0;
    while (i < nums.size() - 1)
    {
        if (nums[i] == nums[i + 1])
        {
            return false;
        }
        sumGap += nums[i + 1] - nums[i] - 1;
        if (sumGap > sumZero)
        {
            return false;
        }
        i++;
    }
    return sumGap > sumZero ? false : true;
}
int main()
{
    vector<int> v = {0,0,0};
    cout << isStraight(v) << endl;
    return 0;
}