#include <iostream>
#include <vector>
using namespace std;
vector<int> printMatrix(vector<vector<int>> matrix)
{
    int row = matrix.size() - 1;
    if (row == -1)
    {
        return {};
    }
    int col = matrix[0].size() - 1;

    vector<int> res;
    int i = 0, j = 0;
    while (i <= row && j <= col)
    {
        for (int k = j; k <= col; k++)
        {
            res.push_back(matrix[i][k]);
        }
        i++;
        for (int k = i; k <= row; k++)
        {
            res.push_back(matrix[k][col]);
        }
        col--;
        if (row - i < 0) // 只有一行
        {
            break;
        }
        for (int k = col; k >= j; k--)
        {
            res.push_back(matrix[row][k]);
        }
        row--;
        if (col - j < 0) // 只有一列
        {
            break;
        }
        for (int k = row; k >= i; k--)
        {
            res.push_back(matrix[k][j]);
        }
        j++;
    }
    return res;
}
int main()
{
    vector<vector<int>> matrix = {{1,2,3}};
    vector<int> res = printMatrix(matrix);
    for (auto r : res)
    {
        cout << r << "->";
    }
    return 0;
}