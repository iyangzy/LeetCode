#include <iostream>
using namespace std;
// 最好想的当然是循环链表，但是太复杂
// 下面是书上的解法，数学分析，代码虽然很简单，但推导过程并不简单
int lastRemaining(int n, int m)
{
    if (n < 1 || m < 1)
    {
        return -1;
    }
    int last = 0;
    for (int i = 2; i <= n; i++)
    {
        last = (last + m) % i;
    }
    return last;
}
int main()
{
    cout << lastRemaining(10, 17);
    return 0;
}