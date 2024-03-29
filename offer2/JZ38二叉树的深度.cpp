#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
// 解2 递归，代码更简洁
int TreeDepth(TreeNode *pRoot)
{
    if (!pRoot)
    {
        return 0;
    }

    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);

    return max(left, right) + 1;
}
// 解1，层序遍历
// int TreeDepth(TreeNode *pRoot)
// {
//     if (!pRoot)
//     {
//         return 0;
//     }

//     queue<TreeNode *> q;
//     q.push(pRoot);
//     int level = 0;
//     while (!q.empty())
//     {
//         level++;
//         int size = q.size();
//         for (int i = 0; i < size; i++)
//         {
//             TreeNode *t = q.front();
//             q.pop();
//             if (t->left)
//             {
//                 q.push(t->left);
//             }
//             if (t->right)
//             {
//                 q.push(t->right);
//             }
//         }
//     }
//     return level;
// }
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    cout << TreeDepth(root) << endl;
    return 0;
}
