#include <iostream>
#include <vector>
using namespace std;
int base = 1337;
int myPow(int a, int k)
{
    if (k == 0)
    {
        return 1;
    }
    a %= base;

    if (k % 2 == 1)
    {
        return (a * myPow(a, k - 1)) % base;
    }
    else
    {
        int sub = myPow(a, k / 2);
        return (sub * sub) % base;
    }

    // int res = 1;
    // for (int i = 0; i < k; i++)
    // {
    //     res *= a;
    //     res %= base;
    // }
    // return res;
}
int superPow(int a, vector<int> &b)
{
    if (b.empty())
    {
        return 1;
    }
    int last = b.back();
    b.pop_back();

    int p1 = myPow(a, last);
    int p2 = myPow(superPow(a, b), 10);
    return (p1 * p2) % base;
}
int main()
{
    vector<int> b = {2, 0, 0};
    cout << superPow(2147483647, b) << endl;
    return 0;
}