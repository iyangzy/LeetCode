#include <iostream>
using namespace std;
int LastRemaining_Solution(int n, int m)
{
    if(n<=0)
    {
        return -1;
    }

    int q = 0;
    for (int i = 2; i <= n; i++)
    {
        q = (q+m)%i;
    }
    return q;
}
int main()
{
    cout<<LastRemaining_Solution(5,3)<<endl;
    return 0;
}