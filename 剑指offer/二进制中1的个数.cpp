#include <iostream>
using namespace std;
/**位运算
 * (n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，此 1 右边的 0 都变成 1 。
 * n&(n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，其余不变。
 */
int hammingWeight(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = (n - 1) & n;
    }
    return count;
}
int main()
{
    cout << hammingWeight(11) << endl;
    return 0;
}
/** 常规位运算
 * 将n不断右移并与1，结果为1则改位为1，但是此情况不使用负数，负数右移会在右边补1，会进入死循环
 * 为应对负数的情况，可以将1左移并与n，效果相同
 */