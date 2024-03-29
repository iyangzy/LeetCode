#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char ch)
{
    for (int i = 0; i < board[row].size(); i++)
    {
        if (board[row][i] == ch)
        {
            return false;
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == ch)
        {
            return false;
        }
    }
    int mr = row == 0 ? 0 : (row / 3) * 3;
    int mc = col == 0 ? 0 : (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[mr + i][mc + j] == ch)
            {
                return false;
            }
        }
    }
    return true;
}
bool backTrack(vector<vector<char>> &board, int row, int col)
{
    if (row == board.size())
    {
        return true;
    }

    if (col == board[row].size())
    {
        return backTrack(board, row + 1, 0);
    }

    if (board[row][col] != '.')
    {
        return backTrack(board, row, col + 1);
    }

    for (char i = '1'; i <= '9'; i++)
    {
        if (!isValid(board, row, col, i))
        {
            continue;
        }

        board[row][col] = i;
        // backTrack(board, row, col + 1);
        if (backTrack(board, row, col + 1))
        {
            return true;
        }
        board[row][col] = '.';
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    backTrack(board, 0, 0);
}
int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    for (auto v : board)
    {
        for (vector<char>::iterator iter = v.begin(); iter < v.end(); iter++)
        {
            cout << *iter << ",";
        }
        cout << endl;
    }
    return 0;
}