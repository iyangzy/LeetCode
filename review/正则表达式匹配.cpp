#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, bool> memo;
bool regularExp(string s, int i, string p, int j)
{
    if (j == p.size())
    {
        return i == s.size();
    }
    else if (i == s.size())
    {
        if ((p.size() - j) & 1)
        {
            return false;
        }
        for (int t = j; t < p.size() - 1; t += 2)
        {
            if (p[t] == '*' || p[t + 1] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (memo.count(pair<int, int>(i, j)))
    {
        return memo[pair<int, int>(i, j)];
    }
    bool res = false;
    if (j < p.size() - 1 && p[j + 1] == '*')
    {
        if (s[i] == p[j] || p[j] == '.')
        {
            res = regularExp(s, i + 1, p, j) || regularExp(s, i, p, j + 2);
        }
        else
        {
            res = regularExp(s, i, p, j + 2);
        }
    }
    else
    {
        if (s[i] == p[j] || p[j] == '.')
        {
            res = regularExp(s, i + 1, p, j + 1);
        }
        else
        {
            res = false;
        }
    }
    memo[pair<int, int>(i, j)] = res;
    return res;
}
bool isMatch(string s, string p)
{
    return regularExp(s, 0, p, 0);
}
int main()
{
    cout << isMatch("bbbba", ".*a*a") << endl;
    return 0;
}