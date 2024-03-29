#include <iostream>
using namespace std;
int jumpFloor(int number)
{
    if (number <= 2)
    {
        return number;
    }

    int p = 1, q = 2, t;
    for (int i = 2; i < number; i++)
    {
        t = p + q;
        p = q;
        q = t;
    }
    return t;
}
int main()
{
    cout << jumpFloor(8) << endl;
    return 0;
}