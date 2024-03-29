#include <iostream>
#include <vector>
using namespace std;
// 力扣官方，分组异或
vector<int> singleNumbers(vector<int> &nums)
{
    int ret = 0;
    for (int n : nums)
    {
        ret ^= n;
    }
    int div = 1;
    while ((div & ret) == 0)
    {
        div <<= 1; // 这是左移
    }
    int n1 = 0, n2 = 0;
    for (int n : nums)
    {
        if (div & n)
        {
            n1 ^= n;
        }
        else
        {
            n2 ^= n;
        }
    }
    return vector<int>{n1, n2};
}
// 书上的分组异或，有点臃肿
// int findFirstBitIs1(int num)
// {
//     int index = 0;
//     while ((((num & 1) == 0) && (index < 8 * sizeof(int))))
//     {
//         num = num >> 1;
//         index++;
//     }
//     return index;
// }
// bool isBit1(int num, int index)
// {
//     num = num >> index;
//     return (num & 1);
// }
// vector<int> singleNumbers(vector<int> &nums)
// {
//     if (nums.size() < 2)
//     {
//         return {};
//     }
//     vector<int> re(2);
//     int res = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         res ^= nums[i];
//     }
//     int index = findFirstBitIs1(res);
//     int n1 = 0, n2 = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (isBit1(nums[i], index))
//         {
//             n1 ^= nums[i];
//         }
//         else
//         {
//             n2 ^= nums[i];
//         }
//     }
//     re[0] = n1;
//     re[1] = n2;
//     return re;
// }
int main()
{
    vector<int> v = {4, 1, 4, 6};
    vector<int> re = singleNumbers(v);
    for (vector<int>::iterator iter = re.begin(); iter < re.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}