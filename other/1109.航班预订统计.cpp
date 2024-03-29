#include <iostream>
#include <vector>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> diff(n, 0);
    for (auto booking : bookings)
    {
        diff[booking[0] - 1] += booking[2];
        if (booking[1] == n)
        {
            continue;
        }
        diff[booking[1]] -= booking[2];
    }
    for (int i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }
    return diff;
}
int main()
{
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    vector<int> answer = corpFlightBookings(bookings, 5);
    for (auto ans : answer)
    {
        cout << ans << "->";
    }
    return 0;
}