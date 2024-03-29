#include<iostream>
#include<string>
using namespace std;
//不使用函数，原地修改，需要对string先resize，时间复杂度挺好
string replaceSpace(string s)
{
    if (s.empty())
    {
        return s;
    }
    int count = 0,length = s.length();
    for (auto ch : s)
    {
        if (ch == ' ')
        {
            count++;
        }
    }
    s.resize(length + count*2);
    for (int i = s.length(); i >= 0; i--)
    {
        if (s[length]==' ')
        {
            s[i--]='0';
            s[i--]='2';
            s[i]='%';
        }
        else
        {
            s[i]=s[length];
        }
        length--;
    }
    return s;
}
//使用string的replace方法，用法比较特殊，注意一下。replace之后自身的值改变了，不用重新赋值
//find函数找不到回返回一个特殊值npos，可以是int
// string replaceSpace(string s)
// {
//     while (s.find(" ") != s.npos)
//     {
//         s.replace(s.find(" "),1,"%20");
//     }
//     return s;
// }
// //最初的想法，也是最基本的，但是果不其然性能太差
// string replaceSpace(string s) {
//         int len = 0;
//         string newStr = "";
//         while(len<s.length())
//         {
//             if(s[len]==' ')
//             {
//                 newStr += "%20";
//             }
//             else
//             {
//                 newStr += s[len];
//             }
//             len++;
//         }
//         return newStr;
//     }
int main()
{
    string s = "We are happy.";
    cout<<replaceSpace(s);
    return 0;
}