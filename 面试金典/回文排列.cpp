#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 回文要注意长度是奇数还是偶数
// 解3 位运算（一般情况下，可以打表也可以通过位运算解决，但是这个题目没有限制字符类型，所以位运算会越界）
bool canPermutePalindrome(string s)
{
    int flag = 0; 
    for (int i = 0; s[i]; i++)
    {
        flag ^= (1 << ((int)s[i]));
        // Line 7: Char 24: runtime error: shift exponent -32 is negative (solution.cpp)
        // SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:17:24
    }
    // 如果字符串可以排列成一个回文串，那么它的每个字符都应该出现偶数次，最多只有一个字符可以出现奇数次
    // 所以，我们检查flag中是否最多只有一位是1
    // 如果是，那么flag & (flag - 1)应该等于0
    return (flag & (flag - 1)) == 0;
}
// 解2 打表、hash，记录每个字符出现的次数，最多只有一个字符的出现次数为奇数
// 解1 排序后看相近的两个元素是否相同
// bool canPermutePalindrome(string s)
// {
//     if (s.empty())
//     {
//         return false;
//     }
//     if (s.size() == 1)
//     {
//         return true;
//     }
//     if (s.size() == 2)
//     {
//         return s[0] == s[1];
//     }

//     sort(s.begin(), s.end());
//     int flag = 0;
//     for (int i = 0; i <= s.size() - 2; i++)
//     {
//         if (s[i] == s[i + 1])
//         {
//             i++;
//             continue;
//         }
//         else if (flag == 0)
//         {
//             flag = 1 - flag;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return s.size() % 2 == 0 ? flag == 0 : true;// 如果字符串长度是偶数，不能有不成对的字符
// }
int main()
{
    string s = "tactcoa"; // true
    cout << canPermutePalindrome(s) << endl;
    string s2 = "as"; // false
    cout << canPermutePalindrome(s2) << endl;
    string s3 = "aa"; // true
    cout << canPermutePalindrome(s3) << endl;
    string s4 = "abc"; // false
    cout << canPermutePalindrome(s4) << endl;
    string s5 = "aabc"; // false
    cout << canPermutePalindrome(s5) << endl;
}