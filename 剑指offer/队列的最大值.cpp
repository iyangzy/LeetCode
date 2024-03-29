#include <iostream>
#include <deque>
#include <vector>
using namespace std;
// 单调队列，结合“滑动窗口的最大值”这个题编写，借鉴力扣官解优化，最终如下。但是性能也没有多好
class MaxQueue
{
public:
    vector<int> q;
    int index;
    deque<int> rec;

    MaxQueue()
    {
        q.clear();
        index = 0;
        rec.clear();
    }

    int max_value()
    {
        return rec.empty() ? -1 : q[rec.front()];
    }

    void push_back(int value)
    {
        q.push_back(value);

        while (!rec.empty() && value > q[rec.back()])
        {
            rec.pop_back();
        }
        rec.push_back(q.size() - 1);
    }

    int pop_front()
    {
        if (!rec.empty() && rec.front() < (index + 1))
        {
            rec.pop_front();
        }
        return index + 1 > q.size() ? -1 : q[index++];
    }
};
int main()
{
    MaxQueue *obj = new MaxQueue();
    obj->push_back(1);
    obj->push_back(2);
    cout << obj->max_value() << endl;
    cout << obj->pop_front() << endl;
    cout << obj->max_value() << endl;
}