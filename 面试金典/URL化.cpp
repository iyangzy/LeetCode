#include <iostream>
#include <string>
using namespace std;
// 倒序遍历，需要注意有的case需截取（有可能空格是有冗余的）
string replaceSpaces(string S, int length)
{
    int j = S.size() - 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (S[i] != ' ')
        {
            S[j--] = S[i];
        }
        else
        {
            S[j--] = '0';
            S[j--] = '2';
            S[j--] = '%';
        }
    }
    return S.substr(j+1);
}
// // 解1 遍历拼接到新的string上
// string replaceSpaces(string S, int length)
// {
//     string newStr;
//     string replaceStr = "%20";
//     for (int i = 0; i < length; i++)
//     {
//         if (S[i] == ' ')
//         {
//             newStr.append(replaceStr);
//         }
//         else
//         {
//             newStr.append(1, S[i]);
//         }
//     }
//     return newStr;
// }
int main()
{
    string s1 = "Mr John Smith    ";
    cout << replaceSpaces(s1, 13) << endl;
    string s2 = "               ";
    cout << replaceSpaces(s2, 5) << endl;
    string s3 = "ds sdfs afs sdfa dfssf asdf             ";
    cout << replaceSpaces(s3, 27) << endl;
}