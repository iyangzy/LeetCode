#include <iostream>
#include <vector>
using namespace std;
// 需要先把所有的0都找出来再改变矩阵的值
void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> row(matrix.size(), 1), col(matrix[0].size(), 1);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = col[j] = 0;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> m1 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    setZeroes(m1);
    for (int i = 0; i < m1.size(); i++)
    {
        for (int j = 0; j < m1[i].size(); j++)
        {
            cout << m1[i][j] << ", ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> m2 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    setZeroes(m2);
    for (int i = 0; i < m2.size(); i++)
    {
        for (int j = 0; j < m2[i].size(); j++)
        {
            cout << m2[i][j] << ", ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> m3 = {
        {1, 0},
        {4, 5}};
    setZeroes(m3);
    for (int i = 0; i < m3.size(); i++)
    {
        for (int j = 0; j < m3[i].size(); j++)
        {
            cout << m3[i][j] << ", ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> m4 = {
        {1, 0}};
    setZeroes(m4);
    for (int i = 0; i < m4.size(); i++)
    {
        for (int j = 0; j < m4[i].size(); j++)
        {
            cout << m4[i][j] << ", ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> m5 = {
        {0},
        {1}};
    setZeroes(m5);
    for (int i = 0; i < m5.size(); i++)
    {
        for (int j = 0; j < m5[i].size(); j++)
        {
            cout << m5[i][j] << ", ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> m6 = {
        {0, 0, 0, 5},
        {4, 3, 1, 4},
        {0, 1, 1, 4},
        {1, 2, 1, 3},
        {0, 0, 1, 1}};
    setZeroes(m6);
    for (int i = 0; i < m6.size(); i++)
    {
        for (int j = 0; j < m6[i].size(); j++)
        {
            cout << m6[i][j] << ", ";
        }
        cout << endl;
    }
}