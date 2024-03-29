#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;
vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (size == 0 || size > num.size())
    {
        return {};
    }

    vector<int> maxNums;
    deque<int> maxIndex;
    int i = 0;
    for (; i < size; i++)
    {
        while (!maxIndex.empty() && num[maxIndex.back()] < num[i])
        {
            maxIndex.pop_back();
        }
        maxIndex.push_back(i);
    }
    for (; i < num.size(); i++)
    {
        maxNums.push_back(num[maxIndex.front()]);
        while (!maxIndex.empty() && num[maxIndex.back()] < num[i])
        {
            maxIndex.pop_back();
        }
        if (!maxIndex.empty() && maxIndex.front() <= i - size)
        {
            maxIndex.pop_front();
        }
        maxIndex.push_back(i);
    }
    maxNums.push_back(num[maxIndex.front()]);
    return maxNums;
}
// 利用堆的有序性
// vector<int> maxInWindows(const vector<int> &num, unsigned int size)
// {
//     if (size == 0 || size > num.size())
//     {
//         return {};
//     }

//     vector<int> ma;
//     multiset<int, greater<int>> win(num.begin(), num.begin() + size);
//     ma.push_back(*win.begin());
//     int pre = 0;
//     for (int i = size; i < num.size(); i++)
//     {
//         multiset<int>::iterator iter = win.find(num[pre++]);
//         win.erase(iter);
//         win.insert(num[i]);
//         ma.push_back(*win.begin());
//     }
//     return ma;
// }
int main()
{
    vector<int> nums = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> maxNums = maxInWindows(nums, 3);
    for (auto ma : maxNums)
    {
        cout << ma << endl;
    }
    return 0;
}