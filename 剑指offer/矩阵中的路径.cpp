#include <iostream>
#include <vector>
using namespace std;
//人家的代码，我觉得我写的跟着差不多，可就是不行疯了。。。
bool dfs(vector<vector<char>> &b, string &w, int i, int j, int k)
{
    if (i >= b.size() || i < 0 || j >= b[0].size() || j < 0 || b[i][j] != w[k])
        return false;
    if (k == w.length() - 1)
        return true;
    char temp = b[i][j];
    b[i][j] = '/';                                    //这样就不用visit数组了，节省空间
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //这里写的挺好
    for (int q = 0; q < 4; q++)
    {
        int m = i + dx[q], n = j + dy[q];
        if (dfs(b, w, m, n, k + 1))
            return true;
    }
    b[i][j] = temp;
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}
int main()
{
    // vector<vector<char>> r = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";
    // vector<vector<char>> r = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string word = "SEE";

    vector<vector<char>> r = {{'a', 'a'}};
    string word = "aaa";
    cout << exist(r, word) << endl;
    return 0;
}
