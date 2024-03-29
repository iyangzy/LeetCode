#include <iostream>
#include <vector>
using namespace std;
//快慢双指针
vector<int> exchange(vector<int> &nums)
{
    int slow = 0, fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] & 1) //不能改成这样  if(nums[fast]&1 && slow!=fast)  你以为这样会省时，但是这样slow状态不会更新，即便当前slow和fast指向相同且是奇数，此时的确不用交换，但是slow不能不动，slow的指向应该是偶数，不动的话指向的是奇数，下次交换将是奇数换奇数，是错误的
        {
            if(!(nums[slow]&1)) swap(nums[slow], nums[fast]);//这里可以加一个当前slow指向是不是奇数的判断，主要是应对初始化时不必要的交换，但是初始化时的情况毕竟较少，直接交换也可，之后每次交换都进行判断可能会显得多余
            slow++;
        }
        fast++;
    }
    return nums;
}
//别写的双指针
// vector<int> exchange(vector<int> &nums)
// {
//     int i=0, j=nums.size()-1;
//     while (i<j)
//     {
//         while(i<j && (nums[i]&1) == 1) i++;//位运算要括起来，不晓得为啥
//         while(i<j && (nums[j]&1) == 0) j--;
//         swap(nums[i],nums[j]);
//     }
//     return nums;
// }
//自己写的双指针，不够纯粹
// vector<int> exchange(vector<int> &nums)
// {
//     int j = nums.size()-1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] % 2 == 0 && i<=j)
//         {
//             while (nums[j] % 2 == 0 && j > i)
//             {
//                 j--;
//             }
//             swap(nums[i], nums[j]);
//             j--;
//         }
//     }

//     return nums;
// }
int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> re = exchange(v);
    for (vector<int>::iterator iter = re.begin(); iter < re.end(); iter++)
    {
        cout << *iter << ",";
    }
    return 0;
}