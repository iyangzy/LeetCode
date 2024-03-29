#include <iostream>
#include <vector>
using namespace std;
// 解1：总结公式：（x2=y1,y2=size-1-x1），然后按层遍历，层内依次旋转每个元素
void rotate(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    if (size == 0)
        return;

    for (int i = 0; i < matrix.size() / 2; i++)
    {
        for (int j = i; j < matrix[i].size() - 1 - i; j++)
        {
            int x1 = i, y1 = j;
            int current = matrix[x1][y1];
            for (int k = 0; k < 4; k++)
            {
                int x2 = y1, y2 = size - 1 - x1;
                int next = matrix[x2][y2];
                matrix[x2][y2] = current;
                current = next;
                x1 = x2;
                y1 = y2;
            }
        }
    }
}
int main()
{
    vector<vector<int>> m1 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    rotate(m1);
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(m2);
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
        {1, 2},
        {4, 5}};
    rotate(m3);
    for (int i = 0; i < m3.size(); i++)
    {
        for (int j = 0; j < m3[i].size(); j++)
        {
            cout << m3[i][j] << ", ";
        }
        cout << endl;
    }
}