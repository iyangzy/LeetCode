#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != mid)
        {
            if (mid == 0 || nums[mid-1] == mid-1)
            {
                return mid;
            }
            high = mid-1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    if (low == nums.size())
    {
        return nums.size();
    }
    
    return -1;
}
int main()
{
    vector<int> v = {0};
    cout<<missingNumber(v)<<endl;
    return 0;
}