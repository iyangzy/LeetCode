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
// 改进后的递归
TreeNode *mirrorTree(TreeNode *root)
{
    if (root)
    {
        TreeNode *t = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(t);       
    }
    return root;
}
// 最初的递归
// TreeNode *mirrorTree(TreeNode *root)
// {
//     if (root)
//     {
//         TreeNode *t = root->left;
//         root->left = root->right;
//         root->right = t;
//         mirrorTree(root->left);
//         mirrorTree(root->right);
//     }
//     return root;
// }
int main()
{
    TreeNode *r = new TreeNode(4);
    r->left = new TreeNode(2);
    r->right = new TreeNode(7);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(3);
    r->right->left = new TreeNode(6);
    r->right->right = new TreeNode(9);
    TreeNode *mirror = mirrorTree(r);
    return 0;
}