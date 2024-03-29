#include <iostream>
#include <vector>
using namespace std;
//二分法，做了点变化
int minArray(vector<int> &numbers)
{
    int low = 0, high = numbers.size() - 1, mid; //high要减1
    // mid = (low + high) / 2;//这么写容易溢出
    mid = low + (high - low) / 2;
    while (low < high)
    {
        if (numbers[mid] > numbers[high])
        {
            low = mid + 1;
        }
        else if (numbers[mid] < numbers[high])
        {
            high = mid; //这里要注意，不能mid+1，这种情况证明此时已经在有序数组中了，可能mid就是最小的元素，不能跳过。毕竟不是真正的二分法，写的时候每个细节都得注意，这个点还有个专门的测试点
        }
        else
        {
            high--;
        }
        // mid = (low + high) / 2;//这么写容易溢出
        mid = low + (high - low) / 2;
    }
    return numbers[low];
}
//最简单的暴力解法。并不是所有数组都旋转过，也有可能没有旋转
// int minArray(vector<int> &numbers)
// {
//     for (int i = 1; i < numbers.size(); i++)
//     {
//         if (numbers[i]<numbers[i-1])
//         {
//             return numbers[i];
//         }

//     }
//     return numbers[0];
// }
int main()
{
    // vector<int> v = {3, 4, 5, 1, 2};
    vector<int> v = {3, 1, 3};

    cout << minArray(v) << endl;
    return 0;
}