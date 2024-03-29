#include <iostream>
#include <queue>
using namespace std;
int indexSum(int row, int column)
{
    int sum = 0;
    while (row > 0)
    {
        sum += row % 10;
        row /= 10;
    }
    while (column > 0)
    {
        sum += column % 10;
        column /= 10;
    }
    return sum;
}
//bfs
int movingCount(int m, int n, int k)
{
    if (k == 0)
    {
        return 1;
    }

    queue<pair<int, int>> pos;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int count = 1;
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    pos.push(make_pair(0, 0));
    vis[0][0] = 1;
    while (!pos.empty())
    {
        auto [row, column] = pos.front();
        pos.pop();
        for (int i = 0; i < 2; i++)
        {
            int tx = dx[i] + row;
            int ty = dy[i] + column;
            if (tx < 0 || tx > m - 1 || ty < 0 || ty > n - 1 || vis[tx][ty] == 1 || indexSum(tx, ty) > k)
            {
                continue;
            }
            pos.push(make_pair(tx, ty));
            vis[tx][ty] = 1;
            count++;
        }
    }
    return count;
}
//这个题没有想象中这么简单，这是最开始的错误思路
// int movingCount(int m, int n, int k)
// {
//     int count = 0;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = n-1; j >= 0; j--)
//         {
//             int indexSum = 0, row = i, column = j;
//             while (row >= 10)
//             {
//                 indexSum += row % 10;
//                 row /= 10;
//             }
//             indexSum += row;
//             while (column >= 10)
//             {
//                 indexSum += column % 10;
//                 column /= 10;
//             }
//             indexSum += column;
//             if (indexSum <= k)
//             {
//                 count += j+1;
//                 break;
//             }
//         }
//         if (n == 0)
//         {
//             break;
//         }
//     }
//     return count;
// }

int main()
{
    cout << movingCount(11, 8, 16) << endl;
    return 0;
}