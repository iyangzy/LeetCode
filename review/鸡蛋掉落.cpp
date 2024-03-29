#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;
// 使用二分查找优化
int dp(int k, int n)
{
    if (k == 1)
        return n;
    if (n == 0)
        return 0;

    if (memo[k][n] != -1)
    {
        return memo[k][n];
    }

    int res = INT32_MAX;
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int broken = dp(k - 1, mid - 1);
        int notBroken = dp(k, n - mid);
        if (notBroken > broken)
        {
            low = mid + 1;
            res = min(res, notBroken + 1);
        }
        else
        {
            high = mid - 1;
            res = min(res, broken + 1);
        }
    }
    memo[k][n] = res;
    return res;
}
// 这是最初的DP，力扣会超时
// int dp(int k, int n)
// {
//     if (k == 1)
//         return n;
//     if (n == 0)
//         return 0;

//     if(memo[k][n] != -1)
//     {
//         return memo[k][n];
//     }

//     int res = INT32_MAX;
//     for (int i = 1; i <= n; i++)
//     {
//         res = min(res, max(dp(k - 1, i - 1), dp(k, n - i)) + 1);
//     }
//     memo[k][n] = res;
//     return res;
// }
int superEggDrop(int k, int n)
{
    memo.resize(k + 1, vector<int>(n + 1, -1));
    return dp(k, n);
}

int main()
{
    cout << superEggDrop(2, 6) << endl;
    return 0;
}