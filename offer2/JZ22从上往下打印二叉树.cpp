#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
// 层序遍历，一次一层
vector<int> PrintFromTopToBottom(TreeNode *root)
{
    if (!root)
    {
        return {};
    }

    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {
            TreeNode *t = q.front();
            q.pop();

            res.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
    }
    return res;
}
// 最原始的层序遍历
// vector<int> PrintFromTopToBottom(TreeNode *root)
// {
//     if (!root)
//     {
//         return {};
//     }

//     vector<int> res;
//     queue<TreeNode *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         TreeNode * t = q.front();
//         q.pop();

//         res.push_back(t->val);
//         if (t->left)
//         {
//             q.push(t->left);
//         }
//         if (t->right)
//         {
//             q.push(t->right);
//         }
//     }
//     return res;
// }
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    vector<int> layer = PrintFromTopToBottom(root);
    for (auto l : layer)
    {
        cout << l << "->";
    }
    return 0;
}