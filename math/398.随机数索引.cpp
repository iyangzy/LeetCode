#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Solution
{
public:
    vector<int> v;
    Solution(vector<int> &nums)
    {
        v = nums;
        srand((int)time(NULL));
    }

    int pick(int target)
    {
        int i=0, res=0, n = v.size();
        for (int j = 0; j < n; j++)
        {
            if (v[j]==target)
            {
                if(rand()%(++i)==0)
                {
                    res = j;
                }
            }   
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution *obj = new Solution(nums);
    int param_1 = obj->pick(3);
    cout << param_1 << endl;
    return 0;
}