#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 迭代
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root && root->val!= val)
    {
        root = val > root->val ? root->right : root->left;
    }
    
    return root;
}
// 递归
// TreeNode *searchBST(TreeNode *root, int val)
// {
//     if (!root)
//     {
//         return nullptr;
//     }

//     if (root->val == val)
//     {
//         return root;
//     }
//     else if (root->val > val)
//     {
//         return searchBST(root->left, val);
//     }
//     else
//     {
//         return searchBST(root->right, val);
//     }
// }
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode *subTree = searchBST(root, 2);
    return 0;
}