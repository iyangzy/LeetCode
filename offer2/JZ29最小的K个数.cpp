#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 借助multiset的自动排序，并且不会去重的特性
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    if (k == 0 || k > input.size())
    {
        return {};
    }
    
    multiset<int> ms(input.begin(),input.end());
    vector<int> res;
    multiset<int>::iterator iter = ms.begin();
    for (int i = 0; i < k; i++,iter++)
    {
        res.push_back(*iter);
    }
    return res;
}
// 借助快排的思想+二分查找
// int partition(vector<int> &input, int l, int r)
// {
//     int i = l, j = r;
//     while (true)
//     {
//         while (j > l && input[--j] > input[l]);
//         while (i < r && input[++i] < input[l]);
//         if (i >= j)
//         {
//             break;
//         }

//         swap(input[i], input[j]);
//     }
//     swap(input[l], input[j]);
//     return j;
// }
// vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
// {
//     if (k == 0 || k > input.size())
//     {
//         return {};
//     }

//     vector<int> res;
//     int l = 0, r = input.size();
//     while (l < r)
//     {
//         int p = partition(input, l, r);
//         if (p < k - 1)
//         {
//             l = p + 1;
//         }
//         else if (p > k - 1)
//         {
//             r = p;
//         }
//         else
//         {
//             return vector<int>(input.begin(), input.begin() + k);
//         }
//     }
//     return {};
// }
int main()
{
    vector<int> input = {4,5,1,6,2,7,3,8};
    // partition(input, 0, input.size() - 1);
    vector<int> res = GetLeastNumbers_Solution(input, 3);
    for (auto v : res)
    {
        cout << v << "->";
    }
    return 0;
}