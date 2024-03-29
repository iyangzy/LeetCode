#include <iostream>
#include <vector>
#include <set>
#include <time.h>
using namespace std;
// 快排
int partition(vector<int> &arr, int start, int end)
{
    if (arr.size() == 0 || start < 0 || end >= arr.size())
    {
        return 0;
    }

    int index = rand() % (end - start + 1) + start;
    int t = arr[index];
    arr[index] = arr[end];
    arr[end] = t;

    int small = start - 1;
    for (index = start; index < end; index++)
    {
        if (arr[index] <= arr[end])
        {
            small++;
            if (small != index)
            {
                t = arr[index];
                arr[index] = arr[small];
                arr[small] = t;
            }
        }
    }
    small++;
    t = arr[small];
    arr[small] = arr[end];
    arr[end] = t;

    return small;
}
void quickSort(vector<int> &arr, int start, int end, int k)
{
    if (start == end || start > end)
    {
        return;
    }
    int index = partition(arr, start, end);
    while (index != k - 1)
    {
        if (index > k - 1)
        {
            end = index - 1;
            index = partition(arr, start, end);
        }
        else
        {
            start = index + 1;
            index = partition(arr, start, end);
        }
    }
}
vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    if (k < 1)
    {
        return {};
    }
    if (arr.size() < k)
    {
        return arr;
    }
    

    srand(time(NULL));
    quickSort(arr, 0, arr.size() - 1, k);
    vector<int> re;
    for (int i = 0; i < k; i++)
    {
        re.push_back(arr[i]);
    }
    return re;
}
// 最大堆
// vector<int> getLeastNumbers(vector<int> &arr, int k)
// {
//     if (k < 1)
//     {
//         return {};
//     }
//     if (arr.size() < k)
//     {
//         return arr;
//     }

//     multiset<int, greater<int>> greaterSet;
//     for (vector<int>::iterator iter = arr.begin(); iter < arr.end(); iter++)
//     {
//         if (greaterSet.size() < k)
//         {
//             greaterSet.insert(*iter);
//         }
//         else
//         {
//             multiset<int, greater<int>>::iterator setBegin = greaterSet.begin();
//             if (*iter < *(greaterSet.begin()))
//             {
//                 greaterSet.erase(setBegin);
//                 greaterSet.insert(*iter);
//             }
//         }
//     }
//     vector<int> mink(greaterSet.begin(), greaterSet.end());
//     return mink;
// }
int main()
{
    vector<int> arr = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> mink = getLeastNumbers(arr, 2);
    for (vector<int>::iterator iter = mink.begin(); iter < mink.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}