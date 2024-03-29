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
        memo.push_back(t);
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