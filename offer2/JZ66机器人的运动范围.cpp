#include <iostream>
#include <vector>
using namespace std;
int digitSum(int row, int col)
{
    int sum = 0;
    while (row > 0)
    {
        sum += (row % 10);
        row /= 10;
    }
    while (col > 0)
    {
        sum += (col % 10);
        col /= 10;
    }
    return sum;
}
int dfs(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &vis)
{
    if (row > rows || col > cols || digitSum(row, col) > threshold || vis[row][col] == 1)
    {
        return 0;
    }

    vis[row][col] = 1;
    return 1 + dfs(threshold, rows, cols, row + 1, col, vis) + dfs(threshold, rows, cols, row, col + 1, vis);
}
int movingCount(int threshold, int rows, int cols)
{
    if (rows == 0 || cols == 0)
    {
        return 0;
    }

    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    return dfs(threshold, rows - 1, cols - 1, 0, 0, vis);
}
int main()
{
    cout << movingCount(5,10,10) << endl;
    return 0;
}