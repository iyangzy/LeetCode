#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 解2 hash 
// 用同一个hash表遍历两遍，第一遍时标志++，第二遍标志--
bool CheckPermutation(string s1, string s2)
{
    if (s1 == s2)
        return true;
    else if (s1.length() != s2.length())
        return false;

    int map[26];
    memset(map, 0, sizeof(map));
    for (int i = 0; s1[i]; i++)
    {
        map[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i]; i++)
    {
        int index = s2[i] - 'a';
        map[index]--;
        if (map[index] < 0)
        {
            return false;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (map[i] != 0)
        {
            return false;
        }
    }
    return true;
}
// // 解法1 排序
// bool CheckPermutation(string s1, string s2)
// {
//     if (s1 == s2)
//         return true;
//     else if (s1.length() != s2.length())
//         return false;

//     sort(s1.begin(), s1.end());
//     sort(s2.begin(), s2.end());
//     return s1 == s2;
// }
int main()
{
    string s1 = "abc", s2 = "bca";
    cout << CheckPermutation(s1, s2) << endl;
    string s3 = "abc", s4 = "bad";
    cout << CheckPermutation(s3, s4) << endl;
}