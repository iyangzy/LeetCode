#include <iostream>
#include<math.h>
using namespace std;
int jumpFloorII(int number)
{
    pow(2,number-1);
    if (number <= 2)
    {
        return number;
    }

    int p = 1, q = 2, t;
    for (int i = 2; i < number; i++)
    {
        t = p + q + 1;
        p = q;
        q = t;
    }
    return t;
}
int main()
{
    cout << jumpFloorII(4) << endl;
    return 0;
}