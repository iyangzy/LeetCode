#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> record;
void backTrack(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        record.push_back(nums);
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        backTrack(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    backTrack(nums, 0);
    return record;
}
int main()
{
    vector<int> nums = {1};
    vector<vector<int>> res = permute(nums);
    for (auto vec : res)
    {
        for (auto v : vec)
        {
            cout << v << "->";
        }
        cout << endl;
    }
    return 0;
}