#include <iostream>
using namespace std;
int NumberOf1(int n)
{
    int i = 0;
    while (n)
    {
        n = n & (n - 1);
        i++;
    }
    return i;
}
int main()
{
    cout << NumberOf1(10) << endl;
    return 0;
}