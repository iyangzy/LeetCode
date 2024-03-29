#include <iostream>
#include <vector>
using namespace std;
class MedianFinder
{
private:
    vector<int> minHeap;
    vector<int> maxHeap;

public:
    MedianFinder()
    {
        minHeap = {};
        maxHeap = {};
    }

    void addNum(int num)
    {
        // 在数据总数目是偶数的时候插入最小堆，否则插入最大堆
        if (((minHeap.size() + maxHeap.size()) & 1) == 0)
        {
            // 如果最大堆中的最大值比新数小，先将新数插入最大堆，并更新堆，再弹出其最大值，并且扔要保持其堆的结构
            if (maxHeap.size() > 0 && num < maxHeap[0])
            {
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end(), less<int>());// 向堆中插入一个元素，并且使堆的规则依然成立

                num = maxHeap[0];

                pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());// 将堆顶元素调整为待弹出元素，剩余元素依然为堆
                maxHeap.pop_back();
            }
            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }
        else
        {
            // 同理
            if (minHeap.size() > 0 && num > minHeap[0])
            {
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());

                num = minHeap[0];

                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
            }
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        }
    }

    double findMedian()
    {
        int size = minHeap.size() + maxHeap.size();
        if (size == 0)
        {
            return NULL;// 这里return NULL不太合适，但这题也不知该return什么
        }
        double median = 0;
        if ((size & 1) == 1)
        {
            median = minHeap[0];
        }
        else
        {
            median = (minHeap[0] + maxHeap[0]) / 2.0;
        }
        return median;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    MedianFinder *obj = new MedianFinder();
    for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++)
    {
        obj->addNum(*iter);
    }
    double param_2 = obj->findMedian();
    cout << param_2 << endl;
    return 0;
}