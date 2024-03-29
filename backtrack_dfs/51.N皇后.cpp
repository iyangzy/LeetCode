#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> res;
bool isValid(vector<string> &board, int row, int col)
{
    int n = board[row].size();
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void backtrack(vector<string> &board, int row)
{
    if (row == board.size())
    {
        res.push_back(board);
        return;
    }

    int n = board[row].size();
    for (int i = 0; i < n; i++)
    {
        if (!isValid(board, row, i))
        {
            continue;
        }
        board[row][i] = 'Q';
        backtrack(board, row + 1);
        board[row][i] = '.';
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
}
int main()
{
    vector<vector<string>> arr;
    arr = solveNQueens(4);
    for (auto v : arr)
    {
        for (vector<string>::iterator iter = v.begin(); iter < v.end(); iter++)
        {
            cout << *iter << ',';
        }
        cout << endl;
    }
    return 0;
}