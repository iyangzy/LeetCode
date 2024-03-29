#include <iostream>
#include <string>
using namespace std;
bool isFlipedString(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    if (s1 == s2)
    {
        return true;
    }

    int strLength = s1.size();
    s2 = s2.append(s2);
    for (int i = 0; i < strLength * 2; i++)
    {
        int j = 0;
        while (s2[j + i] == s1[j])
            j++;
        if (j == strLength)
        {
            return true;
        }
    }
    return false;
}
// 解1 从中间截开 再把左边的串拼到右边
// bool isFlipedString(string s1, string s2)
// {
//     if (s1.size() != s2.size())
//     {
//         return false;
//     }
//     if (s1 == s2)
//     {
//         return true;
//     }

//     for (int i = 0; i < s1.size(); i++)
//     {
//         string left = s1.substr(0, i);
//         string right = s1.substr(i, s1.size());
//         if (right.append(left) == s2)
//         {
//             return true;
//         }
//     }
//     return false;
// }
int main()
{
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << isFlipedString(s1, s2) << endl;

    string s3 = "", s4 = "";
    cout << isFlipedString(s3, s4) << endl;
}