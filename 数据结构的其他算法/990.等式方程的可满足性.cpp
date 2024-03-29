#include <iostream>
#include <vector>
using namespace std;
vector<int> parent(26);
vector<int> size(26);
int find(int x)
{
    while (parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void merge(int m, int n)
{
    int rootM = find(m);
    int rootN = find(n);
    if (rootM == rootN)
    {
        return;
    }
    if (size[rootM] > size[rootN])
    {
        parent[rootN] = rootM;
        size[rootM] += size[rootN];
    }
    else
    {
        parent[rootM] = rootN;
        size[rootN] += size[rootM];
    }
}
bool isConn(int m, int n)
{
    return find(m) == find(n);
}
bool equationsPossible(vector<string> &equations)
{
    if (equations.size() == 0)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < equations.size(); i++)
    {
        if (equations[i][1] == '=')
        {
            merge(equations[i][0] - 'a', equations[i][3] - 'a');
        }
    }
    for (int i = 0; i < equations.size(); i++)
    {
        if (equations[i][1] == '!')
        {
            if (isConn(equations[i][0] - 'a', equations[i][3] - 'a'))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<string> v = {"a==b"};
    cout << equationsPossible(v) << endl;
    return 0;
}