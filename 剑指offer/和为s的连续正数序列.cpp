#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> findContinuousSequence(int target)
{
    vector<vector<int>> res;
    int small = 1, big = 2;
    int sum = small + big;
    int middle = (1 + target) / 2;
    while (small < middle)
    {
        if (sum < target)
        {
            big++;
            sum += big;
        }
        else if (sum > target)
        {
            sum -= small;
            small++;
        }
        else
        {
            vector<int> t;
            for (int i = small; i <= big; i++)
            {
                t.push_back(i);
            }
            res.push_back(t);
            big++;
            sum += big;
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res = findContinuousSequence(3);
    for (auto t : res)
    {
        for (auto i : t)
        {
            cout << i << ',';
        }
        cout << endl;
    }
    return 0;
}