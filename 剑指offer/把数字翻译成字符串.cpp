#include <iostream>
using namespace std;
// 递归
// int translateNum(int num)
// {
//     if (num < 10)
//         return 1;
//     return (num % 100 < 10 || num % 100 > 25) ? translateNum(num / 10) : translateNum(num / 10) + translateNum(num / 100);
// }
// DP + 滚动数组
int translateNum(int num)
{
    string str = to_string(num);
    int p = 0, q = 0, r = 1;
    for (int i = 0; i < str.size(); i++)
    {
        p = q;
        q = r;
        r = q;
        if (i == 0)
        {
            continue;
        }
        auto pre = str.substr(i - 1, 2);
        if (pre >= "10" && pre <= "25")
        {
            r += p;
        }
    }
    return r;
}
int main()
{
    cout << translateNum(12258) << endl;
    return 0;
}