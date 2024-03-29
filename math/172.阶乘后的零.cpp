#include <iostream>
using namespace std;
int trailingZeroes(int n)
{
    int res = 0;
    long div = 5;
    while (div <= n)
    {
        res += (n / div);
        div *= 5;
    }
    return res;
}
int main()
{
    cout << trailingZeroes(5) << endl;
    return 0;
}