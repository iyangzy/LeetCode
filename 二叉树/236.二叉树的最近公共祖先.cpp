#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 后序DFS
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
    {
        return nullptr;
    }
    if (root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
    {
        return root;
    }
    if (!left && !right)
    {
        return nullptr;
    }
    return left ? left : right;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *lca = lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << lca->val << endl;
    return 0;
}