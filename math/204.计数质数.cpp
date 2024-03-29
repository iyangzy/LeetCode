#include <iostream>
#include <vector>
using namespace std;
//Sieve of Eratosthenes 埃氏筛
int countPrimes(int n)
{
    vector<bool> isPrimes(n, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrimes[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isPrimes[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrimes[i])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    cout << countPrimes(10) << endl;
    return 0;
}