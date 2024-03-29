#include <iostream>
using namespace std;
long trailingZeroes(long n)
{
    long res = 0;
    long div = 5;
    while (div <= n)
    {
        res += (n / div);
        div *= 5;
    }
    return res;
}
long left(int k)
{
    long low = 0, high = __LONG_MAX__;
    while (low < high)
    {
        long mid = low + (high - low) / 2;
        if (trailingZeroes(mid) > k)
        {
            high = mid;
        }
        else if (trailingZeroes(mid) < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
long right(int k)
{
    long low = 0, high = __LONG_MAX__;
    while (low < high)
    {
        long mid = low + (high - low) / 2;
        if (trailingZeroes(mid) > k)
        {
            high = mid;
        }
        else if (trailingZeroes(mid) < k)
        {
            low = mid + 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low - 1;
}
int preimageSizeFZF(int k)
{
    return right(k) - left(k) + 1;
}
int main()
{
    cout << preimageSizeFZF(0) << endl;
    return 0;
}