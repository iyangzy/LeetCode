#include <iostream>
#include <vector>
using namespace std;
vector<int> multiply(const vector<int> &A)
{
    int n = A.size();
    vector<int> B(n, 1);
    for (int i = 1; i < n; i++)
    {
        B[i] = B[i - 1] * A[i - 1];
    }
    int t = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        t *= A[i + 1];
        B[i] *= t;
    }
    return B;
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = multiply(A);
    for (auto i : B)
    {
        cout << i << "->";
    }
    return 0;
}