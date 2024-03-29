#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int strStr(string haystack, string needle)
{
    int m = needle.length();
    if (m == 0)
        return m;
    int n = haystack.length();
    vector<vector<int>> dp(m, vector<int>(256, 0));
    dp[0][needle[0]] = 1;
    int x = 0;
    for (int j = 1; j < m; ++j)
    {
        for (int i = 0; i < 256; ++i)
        {
            dp[j][i] = dp[x][i];
        }
        dp[j][needle[j]] = j + 1;
        x = dp[x][needle[j]];
    }

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        j = dp[j][haystack[i]];
        if (j == m)
            return i - m + 1;
    }
    return -1;
    // return haystack.find(needle);//这个题的本质是实现这个find函数
}

int main()
{
    cout << strStr("hello", "ll") << endl;
    return 0;
}