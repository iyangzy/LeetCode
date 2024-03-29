#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// morris遍历，实现反序中序遍历。性能好，但是不好写
TreeNode *getSuccessor(TreeNode *node)
{
    TreeNode *succ = node->right;
    while (succ->left != nullptr && succ->left != node)
    {
        succ = succ->left;
    }
    return succ;
}
TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    TreeNode *node = root;

    while (node != nullptr)
    {
        if (node->right == nullptr)
        {
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
        else
        {
            TreeNode *succ = getSuccessor(node);
            if (succ->left == nullptr)
            {
                succ->left = node;
                node = node->right;
            }
            else
            {
                succ->left = nullptr;
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
        }
    }

    return root;
}
// 中序遍历
// int sum = 0;
// void inOrder(TreeNode *root)
// {
//     if (root)
//     {
//         inOrder(root->right);
//         sum += root->val;
//         root->val = sum;
//         inOrder(root->left);
//     }
// }
// TreeNode *convertBST(TreeNode *root)
// {
//     inOrder(root);
//     return root;
// }
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    convertBST(root);
    return 0;
}