#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
void backTrack(vector<int> &nums, vector<int> &track, int index)
{
    res.push_back(track);
    for (int i = index; i < nums.size(); i++)
    {
        track.push_back(nums[i]);
        backTrack(nums,track,i+1);
        // track.erase(nums[i]);
        track.pop_back();
    }
    
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> track;
    backTrack(nums,track,0);
    return res;
}
int main()
{
    vector<int> nums = {0};
    vector<vector<int>> subs = subsets(nums);
    for(auto v:subs)
    {
        for(vector<int>::iterator iter=v.begin();iter<v.end();iter++)
        {
            cout<<*iter<<",";
        }
        cout<<endl;
    }
    return 0;
}