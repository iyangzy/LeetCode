#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    if (array.empty())
    {
        return vector<int>{};
    }

    vector<int> res(2, sqrt(INT32_MAX));
    int flag = 0, i = 0, j = array.size() - 1;
    while (i < j)
    {
        if (array[i] + array[j] == sum)
        {
            int x = array[i], y = array[j], p = res[0], q = res[1];
            if (x * y < p * q)
            {
                res[0] = x;
                res[1] = y;
                flag = 1;
            }
            i++;
            j--;
        }
        else if (array[i] + array[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return flag ? res : vector<int>{};
}
int main()
{
    vector<int> array = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> res = FindNumbersWithSum(array, 21);
    for (auto r : res)
    {
        cout << r << "->";
    }
    return 0;
}