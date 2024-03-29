#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 按照书上的解法来的，但是力扣对题目做了改动，稍微改动后超时
// 为解决超时，采取的措施
// 递归从str.length()减少到str.length() - 1
// 不使用set去重，递归过程中实时剪枝
// 采取了以上策略还是超时。。。。。。
// 最最最最最最最后，是把函数参数改为全局变量，减少回调传参得以AC，之前不晓得这样还能减少不少时间
vector<string> arr;
string str;
void recur(int index)
{
    if (index == str.length() - 1)
    {
        arr.push_back(str);
    }
    else
    {
        string subStr = "";
        for (int i = index; i < str.length(); i++)
        {
            if (subStr.find(str[i]) != -1)
            {
                continue;
            }
            subStr.push_back(str[i]);

            char t = str[i];
            str[i] = str[index];
            str[index] = t;
            recur(index + 1);
            t = str[index];
            str[index] = str[i];
            str[i] = t;
        }
    }
}
vector<string> permutation(string s)
{
    str = s;
    recur(0);
    return arr;
}
int main()
{
    vector<string> re = permutation("wrivstm");
    for (vector<string>::iterator iter = re.begin(); iter < re.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}