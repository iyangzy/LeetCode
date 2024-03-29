#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> memo;
bool dp(string s, int i, string p, int j)
{
    // base case
    if (j == p.size())
    {
        return i == s.size();
    }
    if (i == s.size())
    {
        if ((p.size() - j) % 2)
        {
            return false;
        }
        else
        {
            for (int t = j; t < p.size() - 1; t += 2)
            {
                if (p[t + 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }
    }
    // 先查看备忘录中有没有
    string key = to_string(i) + ',' + to_string(j);
    if (memo.count(key))
    {
        return memo[key];
    }
    // 选择和状态转移
    bool res = false;
    if (s[i] == p[j] || p[j] == '.')
    {
        // 匹配
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j); // 0次和多次
        }
        else
        {
            res = dp(s, i + 1, p, j + 1); //没有‘*’只能匹配一次
        }
    }
    else
    {
        // 不匹配
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            res = dp(s, i, p, j + 2); // 0次
        }
        else
        {
            res = false; // 不匹配
        }
    }
    memo[key] = res; // 添加到备忘录
    return res;
}
bool match(string str, string pattern)
{
    return dp(str, 0, pattern, 0);
}
int main()
{
    cout << match("aaa", "a*a") << endl;
    return 0;
}