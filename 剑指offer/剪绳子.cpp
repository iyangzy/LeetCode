#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//贪心
// int cuttingRope(int n)
// {
//     if (n < 4)
//     {
//         return n - 1;
//     }
//     int three = n / 3;
//     if (n % 3 == 1)
//     {
//         three--;
//     }

//     return pow(3, three) * (n % 3 == 0 ? 1 : n - 3 * three);
// }
//DP
int cuttingRope(int n)
{
    if (n < 4)
    {
        return n - 1;
    }

    vector<int> v(n+1);//这里要加1，跟后面的for循环对应，虽然vector可以动态增长，在vscode里不报错，但是在力扣中报错
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3; //这里的v[1]、v[2]和v[3]，不是切割的乘积结果，在n>3时可以不用切割，其本身值更大
    int result = 0;
    for (int i = 4; i <= n; i++)
    {
        result = 0;
        for (int j = 1; j <= i/2; j++)//这里优化。这里改后运行时间增加了？？？？？？？？？？？？？？？？内存占用少了一丢丢？？？？
        {
            result = max(result, v[j] * v[i - j]);
        }
        v[i] = result;
    }
    // int num[10];
    // delete[] num;//这是对数组的内存释放

    vector<int>().swap(v);//这里优化，释放内存，vector的内存释放不太友好，只能通过swap强制释放。在力扣中没什么效果

    return result;
}
int main()
{
    cout << cuttingRope(10) << endl;
    return 0;
}