#include <iostream>
using namespace std;
int quickMulti(int A, int B)
{
    int ans = 0;
    for (; B; B >>= 1)
    {
        if (B & 1)
        {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}
// 快速乘
bool quickAdd(int y, int z, int x)
{
    // x 和 y 是负数，z 是正数
    // 需要判断 z * y >= x 是否成立
    int result = 0, add = y;
    while (z)
    {
        if (z & 1)
        {
            // 需要保证 result + add >= x
            if (result < x - add)
            {
                return false;
            }
            result += add;
        }
        if (z != 1)
        {
            // 需要保证 add + add >= x
            if (add < x - add)
            {
                return false;
            }
            add += add;
        }
        // 不能使用除法
        z >>= 1;
    }
    return true;
};

// 被除数 dividend 和除数 divisor
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN)
    {
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            return INT32_MAX;
        }
    }
    if (divisor == INT32_MIN)
    {
        if (dividend == INT32_MIN)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dividend == 0)
    {
        return 0;
    }

    bool isNegative = false;
    if (dividend > 0)
    {
        dividend = -dividend;
        isNegative = !isNegative;
    }
    if (divisor > 0)
    {
        divisor = -divisor;
        isNegative = !isNegative;
    }

    int left = 1, right = INT32_MAX, quotient = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        // int res = quickMulti(mid, divisor);
        if (quickAdd(divisor, mid, dividend))
        {
            quotient = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return isNegative ? -quotient : quotient;
}
int main()
{
    int dividend = 10, divisor = 3;
    cout << divide(dividend, divisor)<<endl;
    int dividend2 = 7, divisor2 = -3;
    cout << divide(dividend2, divisor2)<<endl;
}