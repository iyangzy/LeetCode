#include <iostream>
using namespace std;
//这个解的“与”操作简直秒啊
// int fib(int n)
// {
//     int arr[2] = {0, 1};
//     for (int i = 2; i <= n; ++i)
//     {
//         arr[i & 1] = (arr[0] + arr[1]) % (int)(1e9 + 7);
//     }
//     return arr[n & 1];
// }
//递归超时。。。。。
// int fib(int n)
// {
//     if (n<2)
//     {
//         return n;
//     }
//     return (fib(n-1)+fib(n-2)) % 1000000007;
// }
//多了一个取余操作。。。。。
int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    int f1 = 0, f2 = 1, f;
    for (int i = 2; i <= n; i++)
    {
        f = (f1 + f2) % 1000000007;
        f1 = f2;
        f2 = f;
    }
    return f;
}
int main()
{
    cout << fib(45) << endl;
    return 0;
}