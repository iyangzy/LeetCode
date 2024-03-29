#include <iostream>
using namespace std;
string ReverseSentence(string str)
{
    if (str.empty())
    {
        return str;
    }

    string res = "", tmp = "";
    int flag = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ' && flag == 1)
        {
            res += tmp + ' ';
            tmp = "";
            flag = 0;
        }
        else
        {
            tmp = str[i] + tmp;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        res += tmp;
    }
    return res == "" ? str : res;
}
int main()
{
    cout << ReverseSentence("nowcoder. a am I") << endl;
    return 0;
}