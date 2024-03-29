#include <iostream>
#include <math.h>
using namespace std;
// 解2 贪心
int cutRope(int number)
{

}
// 解1 数学推导的结果，推导过程就。。。。。
// int cutRope(int number)
// {
//     if(number <= 3) return number-1;
//     int a = number/3, b = number%3;
//     if(b==0) return pow(3,a);
//     if(b==1) return pow(3,a-1)*4;
//     return pow(3,a)*2;
// }
int main()
{
    cout << cutRope(8) << endl;
    return 0;
}