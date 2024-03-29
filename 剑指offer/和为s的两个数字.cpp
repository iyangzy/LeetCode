#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    if (nums.size() < 2)
    {
        return {};
    }

    int p = 0, q = nums.size() - 1, sum;
    vector<int> res;
    while (p < q)
    {
        sum = nums[p] + nums[q];
        if (sum < target)
        {
            p++;
        }
        else if (sum > target)
        {
            q--;
        }
        else
        {
            res.push_back(nums[p]);
            res.push_back(nums[q]);
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> v = {45, 46, 67, 73, 74, 74, 77, 83, 89, 98};
    vector<int> res = twoSum(v, 147);
    for (vector<int>::iterator iter = res.begin(); iter < res.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}