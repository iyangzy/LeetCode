#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//贪心+快速幂求余
long long pow1(long long a, long long n, long long mod, int mul)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)//可以判断n是否为偶数。如果是偶数，n&1返回0；否则返回1，为奇数。
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;//右移一位和除以2在数学上是等价的
    }
    res = (res * mul) % mod;
    return (int)(res);
}
int cuttingRope(int n)
{
    if (n <= 3)
        return n - 1;
    int a = n / 3, b = n % 3;
    int mod = 1e9 + 7;
    if (b == 0)
        return pow1(3, a, mod, 1);
    if (b == 1)
        return pow1(3, a - 1, mod, 4);
    return pow1(3, a, mod, 2);
}


//贪心，用pow在大数下有精度损失。普通的求余方法
// int cuttingRope(int n)
// {
//     if (n < 4)
//     {
//         return n - 1;
//     }
//     long long result = 1; //不能用int，损失精度
//     while (n > 4)
//     {
//         n -= 3;
//         result = result * 3 % 1000000007;
//     }

//     return result * n % 1000000007;
// }

int main()
{
    cout << cuttingRope(120) << endl;
    return 0;
}