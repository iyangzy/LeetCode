#include <iostream>
using namespace std;
// DP 按书上的解法不行，力扣上没有限定字符是26个字母，还有其他特殊符号
int lengthOfLongestSubstring(string s)
{
    if (s.length()<=1)
    {
        return s.length();
    }

    int curLength = 0, maxLength = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int preIndex = -1;// 这个找重复元素位置的地方改动了一下
        for (int j = i-1; j >= 0; j--)
        {
            if (s[j]==s[i])
            {
                preIndex = j;
                break;
            }
        }

        if (preIndex < 0 || i - preIndex > curLength)
        {
            curLength++;
        }
        else
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
            }
            curLength = i - preIndex;
        }
        if (curLength > maxLength)
        {
            maxLength = curLength;
        }
    }
    return maxLength;
}
int main()
{
    cout << lengthOfLongestSubstring(" ") << endl;
    return 0;
}