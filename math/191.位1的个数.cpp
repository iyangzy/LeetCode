#include <iostream>
using namespace std;
int hammingWeight(uint32_t n)
{
    int sum=0;
    while (n!=0)
    {
        n&=(n-1);
        sum++;
    }
    return sum;
}
int main()
{
    cout << hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}