#include <iostream>
using namespace std;
// 咱也不知道这是啥解法，反正挺厉害
int countDigitOne(int n)
{
    long digit = 1, res = 0;// 改为long，不然会超出int的范围
    int high = n / 10, cur = n % 10, low = 0;
    while (high != 0 || cur != 0)
    {
        if (cur == 0)
        {
            res += high * digit;
        }
        else if (cur == 1)
        {
            res += high * digit + low + 1;
        }
        else
        {
            res += (high + 1) * digit;
        }
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return res;
}
int main()
{
    cout << countDigitOne(12) << endl;
    return 0;
}