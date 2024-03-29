#include<iostream>
#include<vector>
using namespace std;
int part(vector<int> &nums,int low,int high)
{
    int i = low,j=high+1;
    while(true)
    {
        while(nums[++i]<nums[low])
        {
            if(i==high) break;
        }
        while(nums[--j]>nums[low])
        {
            if(j==low) break;
        }
        if(i>=j)
        {
            break;
        }
        swap(nums[i],nums[j]);
    }
    swap(nums[low],nums[j]);
    return j;
}
void qsort(vector<int> &nums,int low,int high)
{
    if(low >= high) return;

    int p = part(nums,low,high);
    qsort(nums,low,p-1);
    qsort(nums,p+1,high);
}
int main()
{
    vector<int> nums = {5,8,4,2,6,3};
    qsort(nums,0,nums.size()-1);
    for(auto num:nums)
    {
        cout<<num<<"->";
    }
    return 0;
}