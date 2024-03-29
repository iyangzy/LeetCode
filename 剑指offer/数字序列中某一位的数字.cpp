#include <iostream>
#include <sstream>
using namespace std;
// 自己结合书上的思路做出的解，虽然性能有点差，但是AC了
long numsOfIncrease(int bit)
{
    if (bit == 1)
    {
        return 10;
    }
    return 9 * bit * pow(10, bit - 1);
}
int findNthDigit(int n)
{
    if (n < 10)
    {
        return n;
    }

    int bit = 1, result = -1;
    long increase = 0;// increase最后一定是比n大的一个值，n接近int的最大值是，increase的最后一次增加会超出int的范围
    while (n > increase)
    {
        increase = numsOfIncrease(bit++);
        if (n - increase > 0)
        {
            n -= increase;
        }
        else
        {
            bit--;
        }
    }
    int countBit = (n + 1) / bit;
    int currNum = pow(10, bit - 1) + countBit - 1;
    stringstream ss;
    ss << currNum << currNum + 1;
    string str = ss.str();
    str = str[bit - 1 + ((n + 1) % bit)];
    ss.clear();
    ss.str("");
    ss << str;
    ss >> result;
    return result;
}
int main()
{
    cout << findNthDigit(190) << endl;
    return 0;
}