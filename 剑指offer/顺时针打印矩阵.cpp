#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
    {
        return vector<int>();
    }

    int left = 0, up = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
    vector<int> re((right + 1) * (down + 1));
    int count = 0;
    while (count < re.size())
    {
        for (int j = left; j <= right; j++)
        {
            re[count++] = matrix[up][j];
        }
        up++;
        for (int j = up; j <= down; j++)
        {
            re[count++] = matrix[j][right];
        }
        right--;
        if (count >= re.size())
        {
            break;// 在循环的过程中就可能已经遍历完了，比如只有一行一列的情况
        }
        for (int j = right; j >= left; j--)
        {
            re[count++] = matrix[down][j];
        }
        down--;
        for (int j = down; j >= up; j--)
        {
            re[count++] = matrix[j][left];
        }
        left++;
    }
    return re;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}};
    vector<int> re = spiralOrder(matrix);
    for (vector<int>::iterator iter = re.begin(); iter < re.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}