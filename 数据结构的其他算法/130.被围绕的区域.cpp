// 这个题用来练习Union-Find并查集，尽管其不是最优解
// 先用 for 循环遍历棋盘的四边，
// 用 DFS 算法把那些与边界相连的 O 换成一个特殊字符，
// 比如 #；然后再遍历整个棋盘，把剩下的 O 换成 X，把 # 恢复成 O。
// 这样就能完成题目的要求，时间复杂度 O(MN)
// PS 并查集不是面试热点
#include <iostream>
#include <vector>
using namespace std;
int sum; // 这个参数是统计连通分量的，这里没啥用
vector<int> parent;
vector<int> size;
int find(int x)
{
    while (parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void merge(int p, int q)
{
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ)
    {
        return;
    }
    // 这一步算是个优化，为了保持树的平衡
    if (size[rootP] > size[rootQ])
    {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
    else
    {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }
    // sum--;
}
bool connented(int p, int q)
{
    int rootP = find(p);
    int rootQ = find(q);
    return rootP == rootQ;
}
int countNode()
{
    return sum;
}

void solve(vector<vector<char>> &board)
{
    if (board.size() == 0)
    {
        return;
    }

    int row = board.size();
    int col = board[0].size();
    // sum = row*col;
    int dummy = row * col;
    parent.resize(dummy + 1);
    size.resize(dummy + 1);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            parent[i * col + j] = i * col + j; // 这个坐标转化还得再练练，要搞清楚是乘行还是列
            size[i * col + j] = 1;
        }
    }
    parent[dummy] = dummy;
    size[dummy] = 1;

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout<<parent[i*col+j]<<',';
    //     }
    //     cout<<endl;
    // }
    // 将首列和末列的 O 与 dummy 连通
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == 'O')
        {
            merge(i * col, dummy);
        }
        if (board[i][col - 1] == 'O')
        {
            merge(i * col + col - 1, dummy);
        }
    }
    // 将首行和末行的 O 与 dummy 连通
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == 'O')
        {
            merge(i, dummy);
        }
        if (board[row - 1][i] == 'O')
        {
            merge(col * (row - 1) + i, dummy);
        }
    }
    int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            if (board[i][j] == 'O')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    if (board[x][y] == 'O')
                    {
                        merge(x * col + y, i * col + j);
                    }
                }
            }
        }
    }
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            if (!connented(dummy, i * col + j))
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main()
{
    vector<vector<char>> v = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    for (vector<char> row : v)
    {
        for (char col : row)
        {
            cout << col << ',';
        }
        cout << endl;
    }
    solve(v);
    cout << endl;
    for (vector<char> row : v)
    {
        for (char col : row)
        {
            cout << col << ',';
        }
        cout << endl;
    }
    return 0;
}