#include <iostream>
#include <string>
#include <vector>
using namespace std;
//DP2
bool isMatch(string s, string p)
{
    int m = s.length();
    int n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < n + 1; i++)
    {
        if (i >= 2 && p[i - 1] == '*' && dp[0][i - 2] == true)
        {
            dp[0][i] = true;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if ((p[j - 1] != '*' && p[j - 1] == s[i - 1]) || p[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (j >= 2 && p[j - 1] == '*')
            {
                if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                {
                    dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]; //三个或，分别代表“x*”出现0次、1次和多次
                }
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}
// DP1
// bool isMatch(string s, string p)
// {
//     int m = s.length();
//     int n = p.length();
//     vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (j == 0)
//             {
//                 f[i][j] = i == 0;
//             }
//             else
//             {
//                 if (p[j - 1] != '*')
//                 {
//                     if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
//                     {
//                         f[i][j] = f[i - 1][j - 1];
//                     }
//                 }
//                 else
//                 {
//                     //当遇到*时，分为看与不看两种情况
//                     //不看
//                     if (j >= 2)
//                     {
//                         f[i][j] = (f[i][j] || f[i][j - 2]);
//                     }
//                     //看
//                     if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
//                     {
//                         f[i][j] = (f[i][j] || f[i - 1][j]);
//                     }
//                 }
//             }
//         }
//     }
//     return f[m][n];
// }
/** 自己写的，败在了下面这种情况，还是得往算法上靠
 * "aaa"
 * "ab*a*c*a"
 */
// bool isMatch(string s, string p)
// {
//     int sIndex = 0, pIndex = 0;
//     while (pIndex < p.size())
//     {
//         if (p[pIndex] == '.')
//         {
//             if (pIndex + 1 < p.size())
//             {
//                 if (p[pIndex + 1] == '*')
//                 {
//                     if (pIndex + 2 == p.size())
//                     {
//                         return true;
//                     }
//                     else
//                     {
//                         while (sIndex < s.size())
//                         {
//                             if (s[sIndex] == p[pIndex + 2])
//                             {
//                                 break;
//                             }
//                             sIndex++;
//                         }
//                         pIndex += 2;
//                     }
//                 }
//                 else
//                 {
//                     pIndex++;
//                     sIndex++;
//                 }
//             }
//             else
//             {
//                 pIndex++;
//                 sIndex++;
//             }
//         }
//         else if (pIndex + 1 < p.size() && p[pIndex + 1] == '*')
//         {
//             int count = 0;
//             while (sIndex < s.size())
//             {
//                 if (s[sIndex] != p[pIndex])
//                 {
//                     break;
//                 }
//                 sIndex++;
//                 count++;
//             }
//             if (pIndex + 2 < p.size())
//             {
//                 if (p[pIndex] == p[pIndex + 2])
//                 {
//                     pIndex += count - 2;
//                 }
//             }
//             pIndex += 2;
//         }
//         else if (s[sIndex] == p[pIndex])
//         {
//             sIndex++;
//             pIndex++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     if (sIndex != s.size() || pIndex != p.size())
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }
int main()
{
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
    cout << isMatch("mississippi", "mis*is*ip*.") << endl;
    return 0;
}