#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSymmetric(TreeNode *leftTree, TreeNode *rightTree)
{
    if (!leftTree && !rightTree)
    {
        return true;
    }
    if (!leftTree || !rightTree)
    {
        return false;
    }
    if (leftTree->val != rightTree->val)
    {
        return false;
    }

    return isSymmetric(leftTree->left, rightTree->right) && isSymmetric(leftTree->right, rightTree->left);
}
bool isSymmetric(TreeNode *root)
{
    return isSymmetric(root, root);
}
int main()
{
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(2);
    r->left->left = new TreeNode(3);
    r->left->right = new TreeNode(4);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(3);
    cout << isSymmetric(r);
    return 0;
}