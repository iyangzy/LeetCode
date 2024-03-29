#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> Print(TreeNode *pRoot)
{
    vector<vector<int>> memo;
    if (pRoot == nullptr)
    {
        return memo;
    }

    queue<TreeNode *> q;
    q.push(pRoot);
    int flag = 0;
    while (!q.empty())
    {
        int len = q.size();
        vector<int> t(len);
        for (int i = 0; i < len; i++)
        {
            TreeNode *curNode = q.front();
            q.pop();
            t[i] = curNode->val;
            if (curNode->left)
            {
                q.push(curNode->left);
            }
            if (curNode->right)
            {
                q.push(curNode->right);
            }
        }
        if (flag == 0)
        {
            memo.push_back(t);
        }
        else
        {
            memo.push_back({t.rbegin(), t.rend()});
        }
        flag = 1 - flag;
    }
    return memo;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    vector<vector<int>> res = Print(root);
    for (auto vec : res)
    {
        for (auto v : vec)
        {
            cout << v << "->";
        }
    }
    return 0;
}
int part(vector<int> &num, int low, int high)
{
    int i = low, j = high + 1;
    while (true)
    {
        while (num[++i] < num[low])
        {
            if (i == high)
                break;
        }
        while (num[--j] > num[low])
        {
            if (j == low)
                break;
        }
        if (i > j)
        {
            break;
        }
        swap(num[i], num[j]);
    }
    swap(num[low], num[j]);
    return j;
}