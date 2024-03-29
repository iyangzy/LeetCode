#include <iostream>
#include <vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array)
{
    if (array.empty())
    {
        return 0;
    }

    int n = array.size(), dp = 0, maNums = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if(dp<=0)
        {
            dp = array[i];
        }
        else
        {
            dp += array[i];
        }
        maNums = max(maNums,dp);
    }
    return maNums;
}
int main()
{
    vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    cout << FindGreatestSumOfSubArray(array) << endl;
    return 0;
}