#include <iostream>
using namespace std;
// 非递归快速幂
double Power(double base, int exponent)
{
    if (exponent < 0)
    {
        base = 1 / base;
        exponent = -exponent;
    }

    double x = base, ret = 1.0;
    while (exponent)
    {
        if (exponent & 1)
        {
            ret *= x;
        }
        x *= x;
        exponent >>= 1;
    }
    return ret;
}
// 递归快速幂
// double rec_power(double b, int e)
// {
//     if (e == 0)
//     {
//         return 1.0;
//     }
//     double ret = rec_power(b, e / 2);
//     if (e & 1)
//     {
//         return ret * ret * b;
//     }
//     else
//     {
//         return ret * ret;
//     }
// }
// double Power(double base, int exponent)
// {
//     if (exponent < 0)
//     {
//         base = 1 / base;
//         exponent = -exponent;
//     }
//     return rec_power(base, exponent);
// }
int main()
{
    cout << Power(3.0, 6) << endl;
    return 0;
}