#include <iostream>
#include <vector>
using namespace std;
// 统计二进制中每位出现的次数，整除3后恢复其真实值
int singleNumber(vector<int> &nums)
{
    int bitSum[32] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        int bitMask = 1;
        for (int j = 31; j >= 0; j--)
        {
            int bit = nums[i] & bitMask;
            if (bit)
            {
                bitSum[j]++;
            }
            bitMask = bitMask << 1;
        }
    }
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }
    return result;
}
int main()
{
    vector<int> v{3, 4, 3, 3};
    cout << singleNumber(v) << endl;
    return 0;
}