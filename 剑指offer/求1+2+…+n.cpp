#include <iostream>
using namespace std;
// 书上有四种解法：构造函数、虚函数、函数指针、模板类型，要求对C++的掌握度较高，还得再学学这些东西
// 力扣官方解法：递归+逻辑运算符短路性质、快速乘+位运算
int sumNums(int n)
{
    n && (n += sumNums(n - 1));
    return n;
}
int main()
{
    cout << sumNums(3) << endl;
    return 0;
}