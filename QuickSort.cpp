#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int i = low, j = high + 1;
    while (true) {                          //内循环元素移动次数少
        while (nums[++i] < nums[low])   if (i == high)  break;
        while (nums[--j] > nums[low])   if (j == low)   break;
        if (i >= j)     break;
        swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void quick_sort(vector<int>& nums, int low, int high) {
    if (low >= high)    return;             //循环终止条件

    int j = partition(nums, low, high);     //原地切分
    quick_sort(nums, low, j - 1);
    quick_sort(nums, j + 1, high);
}



int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length == 0 || start < 0 || end >= length)
    {
        throw "Invalid Parameters";
    }

    int index = rand() % (end - start + 1) + start;// 取start到end范围内的随机数
    int t = data[index];
    data[index] = data[end];
    data[end] = t;

    int small = start - 1;
    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            small++;
            if (small != index)
            {
                t = data[index];
                data[index] = data[small];
                data[small] = t;
            }
        }
    }
    small++;
    t = data[small];
    data[small] = data[end];
    data[end] = t;

    return small;
}
void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
    {
        return;
    }

    int index = Partition(data, length, start, end);
    if (index > start)
    {
        QuickSort(data, length, start, index - 1);
    }
    if (index < end)
    {
        QuickSort(data, length, index + 1, end);
    }
}
int main()
{
    srand(time(NULL));
    int nums[10] = {1, 5, 9, 0, 6, 5, 8, 2, 3, 4};
    QuickSort(nums, 10, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << nums[i] << "->";
    }
    return 0;
}