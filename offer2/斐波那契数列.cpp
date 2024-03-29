#include <iostream>
using namespace std;
int Fibonacci(int n)
{
    if (n == 0)
    {
        return n;
    }
    if (n <= 2)
    {
        return 1;
    }

    int i = 1, j = 1, k;
    for (int t = 2; t < n; t++)
    {
        k = i + j;
        i = j;
        j = k;
    }
    return k;
}
int main()
{
    cout << Fibonacci(3);
    return 0;
}