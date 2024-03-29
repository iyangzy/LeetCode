#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    while (num2 != 0)
    {
        int c = (unsigned(num1 & num2)) << 1;
        num1 ^= num2;
        num2 = c;
    }
    return num1;
}
int main()
{
    cout << Add(2, 3) << endl;
    return 0;
}