#include <iostream>
using namespace std;
// 利用逻辑运算符的短路特性
int Sum_Solution(int n)
{
    n && (n += Sum_Solution(n - 1));
    return n;
}
int main()
{
    cout << Sum_Solution(5) << endl;
    return 0;
}