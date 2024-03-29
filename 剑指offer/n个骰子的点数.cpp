#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// dp
vector<double> dicesProbability(int n)
{
    int dp[70]; // n<=11
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 6; i++)
    {
        dp[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 6 * i; j >= i; j--)
        {
            dp[j] = 0;
            for (int k = 1; k <= 6; k++)
            {
                if (j - k < i - 1)
                {
                    break;
                }
                dp[j] += dp[j - k];
            }
        }
    }
    int all = pow(6, n);
    vector<double> res;
    for (int i = n; i <= 6 * n; i++)
    {
        res.push_back(dp[i] * 1.0 / all);
    }
    return res;
}
int main()
{
    vector<double> res = dicesProbability(2);
    for (vector<double>::iterator iter = res.begin(); iter < res.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}