#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 法1：双指针，先反转整个字符串，再反转每个单词
// 法2：分割单词，用栈存储，实现反转
// 我的：分割单词，使用vector存储，倒序遍历vector
// 特例：利用streamstring，貌似可以利用空格做分隔符
string reverseWords(string s)
{
    vector<string> words;
    string t = "";
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            if (t != "")
            {
                words.push_back(t);
            }
            t = "";
        }
        else
        {
            t.push_back(s[i]);
        }
        i++;
    }
    if (t != "")
    {
        words.push_back(t);
    }
    t = "";
    for (i = words.size() - 1; i >= 0; i--)
    {
        t.append(words[i] + ' ');
    }
    return t.substr(0, t.length() - 1);
}
int main()
{
    cout << reverseWords("blue   ") << endl;
    return 0;
}