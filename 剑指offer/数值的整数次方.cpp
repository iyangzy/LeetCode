#include <iostream>
#include <iomanip>
using namespace std;
//快速幂，也并不很快。。。。。
double myPow(double x, int n)
{
    int flag = 0;
    long m = n;
    if (n < 0)
    {
        flag = 1;
        // n = -n;//溢出，整型的最大负数不能直接转换成正数会溢出。
        m = -m;
    }

    double res = 1.00000;
    while (m)
    {
        if (m & 1)
        {
            res *= x;
        }
        x *= x;
        m >>= 1;
    }
    if (flag)
    {
        return 1.00000 / res;
    }
    return res;
}
//超时，意料之中
// double myPow(double x, int n)
// {
//     double res = 1.00000;
//     for (int i = 0; i < fabs(n); i++)
//     {
//         res *= x;
//     }
//     if (n<0)
//     {
//         res = 1.00000/res;
//     }
//     return res;
// }
int main()
{
    cout << myPow(2.00000, -2) << endl;
    return 0;
}