#include <iostream>
#include <unordered_map>
using namespace std;
// 滑动窗口
string minWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for (char c : t)
    {
        need[c]++;
    }

    int left = 0, right = 0;// 当前窗口的左右边界
    int valid = 0;// 当前窗口中含t中字符的个数
    int start = 0, len = INT32_MAX;// 符合要求的子串的左边界和长度
    while (right < s.size())
    {
        char c = s[right];
        right++;
        if (need.count(c))
        {
            window[c]++;
            if (window[c] == need[c])
            {
                valid++;
            }
        }

        while (valid == need.size())
        {
            if (right - left < len)
            {
                len = right - left;
                start = left;
            }
            char d = s[left];
            left++;
            if (need.count(d))
            {
                if (window[d] == need[d])
                {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return len == INT32_MAX ? "" : s.substr(start, len);
}
int main()
{
    cout << minWindow("a", "a") << endl;
    return 0;
}