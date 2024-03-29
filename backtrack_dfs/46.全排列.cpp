//
// Created by yang on 2021/4/19.
//
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
void backtrack(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[i], nums[index]);
        backtrack(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    backtrack(nums, 0);
    return res;
}
int main()
{
    vector<vector<int>> arr;
    vector<int> nums = {1, 2, 3};
    arr = permute(nums);
    for (auto v : arr)
    {
        for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++)
        {
            cout << *iter << ',';
        }
        cout << endl;
    }
    return 0;
}