#include <iostream>
#include <vector>
using namespace std;
//没思路就找一下规律
int numWays(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 3)
    {
        return n;
    }
    int f1 = 1, f2 = 2, f;
    for (int i = 3; i <= n; i++)
    {
        f = (f1 + f2) % 1000000007;
        f1 = f2;
        f2 = f;
    }
    return f;
}
int main()
{
    cout << numWays(7) << endl;
    return 0;
}