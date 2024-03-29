#include <iostream>
#include <vector>
using namespace std;
// 开始查找的位置是右上角，左下角也可，但是不能是左上角或右下角，因为其并不能排除一整行或一整列
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0)
    {
        return false;
    }
    int row = 0,col = matrix[0].size()-1;
    while(row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> v = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << findNumberIn2DArray(v, 5);
    return 0;
}