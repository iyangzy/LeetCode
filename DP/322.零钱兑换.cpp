#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    vector<int> charge(amount + 1, amount + 1);
    charge[0] = 0;
    for (int i = 1; i < charge.size(); i++)
    {
        for (int coin : coins)
        {
            if (i - coin < 0)
            {
                continue;
            }
            charge[i] = min(charge[i], 1 + charge[i - coin]);
        }
    }
    return charge[amount] == amount + 1 ? -1 : charge[amount];
}
int main()
{
    vector<int> coins = {1};
    cout << coinChange(coins, 2);
    return 0;
}