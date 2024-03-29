#include <iostream>
using namespace std;
// 位运算
// 通过异或得到了本位和，通过与运算得到了进位值，最后，只需要将进位值给高一位即可。
int add(int a, int b)
{
    int sum, carry;
    do
    {
        sum = a ^ b;
        carry = (unsigned int)(a & b) << 1; // LeetCode中国版的C++好像不支持负值左移
        a = sum;
        b = carry;
    } while (b != 0);
    return a;
}
int main()
{
    cout << add(1, 3) << endl;
    return 0;
}