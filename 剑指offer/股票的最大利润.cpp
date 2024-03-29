#include <iostream>
#include <vector>
using namespace std;
// 书上的解法，没牵扯算法，但是，但是，大佬K说这是DP
int maxProfit(vector<int> &prices)
{
    if (prices.size() < 2)
    {
        return 0;
    }
    int mi = prices[0];
    int diff = prices[1] - mi;
    for (int i = 2; i < prices.size(); i++)
    {
        if (prices[i - 1] < mi)
        {
            mi = prices[i - 1];
        }
        int t = prices[i] - mi;
        if (t > diff)
        {
            diff = t;
        }
    }
    return diff < 0 ? 0 : diff;
}
int main()
{
    vector<int> v = {7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
    return 0;
}