#include <iostream>
using namespace std;
// DP 空间换时间 丑数 == 某较小丑数 × 某因子（2，3，5）
// 丑数的定义要仔细琢磨
int nthUglyNumber(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int dp[n], index2 = 0, index3 = 0, index5 = 0;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int n2 = dp[index2] * 2, n3 = dp[index3] * 3, n5 = dp[index5] * 5;
        dp[i] = min(min(n2, n3), n5);
        if (dp[i] == n2)
        {
            index2++;
        }
        if (dp[i] == n3)
        {
            index3++;
        }
        if (dp[i] == n5)
        {
            index5++;
        }
    }
    return dp[n - 1];
}
int main()
{
    cout << nthUglyNumber(1) << endl;
    return 0;
}