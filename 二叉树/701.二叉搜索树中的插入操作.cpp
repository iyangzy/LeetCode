#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode *res = insertIntoBST(root, 5);
    return 0;
}