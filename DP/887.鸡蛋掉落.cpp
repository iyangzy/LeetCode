#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int dp(int k, int n)
{
    if (n == 0)
        return 0;
    if (k == 1)
        return n;
    if (memo[k][n] != -1)
        return memo[k][n];

    int res = INT32_MAX, low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int broken = dp(k - 1, mid - 1);
        int not_broken = dp(k, n - mid);
        if (broken > not_broken)
        {
            high = mid - 1;
            res = min(res, broken + 1);
        }
        else
        {
            low = mid + 1;
            res = min(res, not_broken + 1);
        }
    }
    memo[k][n] = res;
    return res;
}

int superEggDrop(int k, int n)
{
    memo.resize(k + 1, vector<int>(n + 1, -1));
    return dp(k, n);
}
int main()
{
    cout<<superEggDrop(2,100)<<endl;
    return 0;
}