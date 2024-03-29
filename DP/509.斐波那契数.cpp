#include <iostream>
using namespace std;
int fib(int n)
{
    if (n<1)
    {
        return 0;
    }
    if (n==1 || n==2)
    {
        return 1;
    }
    int pre = 1, cur = 1;
    for (int i = 3; i <= n; i++)
    {
        int t = pre + cur;
        pre = cur;
        cur = t;
    }
    return cur;
}
int main()
{
    cout << fib(5) << endl;
    return 0;
}