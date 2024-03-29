#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// 我一开始也想到要存储最大值和次最大值，但是具体的逻辑一时间想不明白，下面是参考书上的代码，江湖人称——单调队列
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() == 0 || k == 0)
    {
        return {};
    }

    vector<int> maxInWin;
    deque<int> rec;
    int i = 0;
    for (; i < k; i++)
    {
        while (!rec.empty() && nums[i] > nums[rec.back()])
        {
            rec.pop_back();
        }
        rec.push_back(i);
    }
    for (; i < nums.size(); i++)
    {
        maxInWin.push_back(nums[rec.front()]);
        while (!rec.empty() && nums[i] > nums[rec.back()])
        {
            rec.pop_back();
        }
        if (!rec.empty() && rec.front() <= (i - k))
        {
            rec.pop_front();
        }
        rec.push_back(i);
    }
    maxInWin.push_back(nums[rec.front()]);
    return maxInWin;
}
int main()
{
    vector<int> v = {1, -1};
    vector<int> res = maxSlidingWindow(v, 1);
    for (vector<int>::iterator iter = res.begin(); iter < res.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}