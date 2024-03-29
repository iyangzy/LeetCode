#include <iostream>
#include <vector>
using namespace std;
// 二分
int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.empty())
    {
        return 0;
    }

    int low = 0, high = rotateArray.size() - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (rotateArray[mid] < rotateArray[high])
        {
            high = mid;
        }
        else if (rotateArray[mid] > rotateArray[high])
        {
            low = mid + 1;
        }
        else
        {
            high--;
        }
    }
    return rotateArray[low];
}
// 普通遍历
// int minNumberInRotateArray(vector<int> rotateArray)
// {
//     if (rotateArray.empty())
//     {
//         return 0;
//     }

//     for (int i = 1; i < rotateArray.size(); i++)
//     {
//         if (rotateArray[i]<rotateArray[i-1])
//         {
//             return rotateArray[i];
//         }
//     }
//     return 0;
// }
int main()
{
    vector<int> array = {3, 4, 5, 1, 2};
    cout << minNumberInRotateArray(array) << endl;
    return 0;
}