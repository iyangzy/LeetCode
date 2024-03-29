#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 不能从左上角直接开始遍历，这样效率太低会超时的
bool Find(int target, vector<vector<int>> array)
{
    if (array.empty())
    {
        return false;
    }

    int row = 0, col = array[0].size() - 1;
    while (row < array.size() && col >= 0)
    {
        if (array[row][col] > target)
        {
            col--;
        }
        else if (array[row][col] < target)
        {
            row++;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> array = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout << Find(3, array) << endl;
    return 0;
}