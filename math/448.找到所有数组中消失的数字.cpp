#include <iostream>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int t = (nums[i] - 1) % n;
        nums[t] += n;
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= n)
        {
            res.push_back(i + 1);
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> dis = findDisappearedNumbers(nums);
    for (auto num : dis)
    {
        cout << num << "->";
    }
    return 0;
}