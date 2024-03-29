#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// 方向数组还可以这么写
// vector<int> direction = {1,0,-1,0,1};
// int x = i + direction[k];
// int y = j + direction[k + 1];
bool dfs(vector<vector<char>> ma, string word, int row, int col, vector<vector<int>> &vis)
{
    if (word.length() == 0)
    {
        return true;
    }

    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + direction[i][0], newCol = col + direction[i][1];
        if (newRow < 0 || newRow >= ma.size() || newCol < 0 || newCol >= ma[0].size())
        {
            continue;
        }

        if (ma[newRow][newCol] == word[0] && vis[newRow][newCol] == 0)
        {
            string cur = word.substr(1, word.length());
            if (dfs(ma, cur, newRow, newCol, vis))
            {
                return true;
            }
            vis[newRow][newCol] = 0;
        }
    }
    return false;
}
bool hasPath(vector<vector<char>> &matrix, string word)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }

    vector<vector<int>> vis;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == word[0])
            {
                vis.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
                string cur = word.substr(1, word.length());
                if (dfs(matrix, cur, i, j, vis))
                {
                    return true;
                }
                vector<vector<int>>().swap(vis);
            }
        }
    }
    vector<vector<int>>().swap(vis);
    return false;
}
int main()
{
    vector<vector<char>> matrix = {{}, {}, {}};
    cout << hasPath(matrix, "abcced");
    return 0;
}

int part(int *num, int low, int high)
{
    int i = low, j = high + 1;
    while (true)
    {
        while (num[++i] < num[low])
        {
            if (i == high)
            {
                break;
            }
        }
        while (num[--j] > num[low])
        {
            if (j == low)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        swap(num[i], num[j]);
    }
    swap(num[low], num[j]);
    return j;
}