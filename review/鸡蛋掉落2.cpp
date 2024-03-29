#include <iostream>
#include <vector>
using namespace std;
// 这是自己写的，按理说思路是一样的，但是结果不对
// int dp(int k, int low, int high)
// {
//     if (low >= high)
//     {
//         return 0;
//     }
//     if (k == 1)
//     {
//         return high - low + 1;
//     }

//     int res = INT32_MAX, l = low, h = high;
//     while (l <= h)
//     {
//         int mid = (h + l) / 2;
//         int borken = dp(k - 1, l, mid - 1);
//         int not_broken = dp(k, mid + 1, h);
//         if (borken > not_broken)
//         {
//             h = mid - 1;
//             res = min(res, borken + 1);
//         }
//         else
//         {
//             l = mid + 1;
//             res = min(res, not_broken + 1);
//         }
//     }
//     return res;
// }
vector<vector<int>> memo;
int dp(int k, int n)
{
    if (n == 0)
        return 0;
    if (k == 1)
        return n;
    if(memo[k][n] != -1)
    {
        return memo[k][n];
    }

    int res = INT32_MAX, low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int borken = dp(k - 1, mid - 1);
        int not_broken = dp(k, n - mid);
        if (borken > not_broken)
        {
            high = mid - 1;
            res = min(res, borken + 1);
        }
        else
        {
            low = mid + 1;
            res = min(res, not_broken + 1);
        }
    }
    memo[k][n] = res;
    return res;
}
int superEggDrop(int k, int n)
{
    memo.resize(k+1,vector<int>(n+1,-1));
    return dp(k, n);
}
int main()
{
    cout << superEggDrop(3, 14) << endl;
    return 0;
}