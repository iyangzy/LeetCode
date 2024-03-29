#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int> data, int low, int high, int k)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == k)
        {
            return mid;
        }
        else if (data[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int GetNumberOfK(vector<int> data, int k)
{
    int n = data.size();
    int index = bs(data, 0, n - 1, k);
    if (index == -1)
    {
        return 0;
    }
    int count = 0, i = index;
    while (data[i--] == k)
        count++;
    while (data[++index] == k)
        count++;
    return count;
}
int main()
{
    vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    cout << GetNumberOfK(data, 3);
    return 0;
}