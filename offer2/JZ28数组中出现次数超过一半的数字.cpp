#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 候选法，此题最优解
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    int cond = -1, cnt = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (cnt == 0)
        {
            cond = numbers[i];
            cnt++;
        }
        else
        {
            if (cond == numbers[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }
    // 再检查一遍
    cnt = 0;
    for (const int k : numbers)
    {
        if (cond == k)
            ++cnt;
    }
    if (cnt > numbers.size() / 2)
    {
        return cond;
    }
    return 0;
}
// 排序，众数肯定在数组中间位置
// int MoreThanHalfNum_Solution(vector<int> numbers)
// {
//     sort(numbers.begin(), numbers.end());
//     return numbers[numbers.size() / 2];
// }
int main()
{
    vector<int> num = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << MoreThanHalfNum_Solution(num) << endl;
    return 0;
}