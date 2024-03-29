#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, w, k;
    vector<int> nums;   //这是动态数组
    cin >> n >> w >> k; //这就读入
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int sum = 0, day = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] + day * k > w)
        {
            sum += (nums[i] + day * k - w);
            day++;
        }
    }
    cout << sum << endl;//输出
    return 0;
}