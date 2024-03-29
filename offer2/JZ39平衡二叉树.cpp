#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
// 解2，利用后序遍历，每个节点访问一次
bool IsBalanced(TreeNode *root, int *depth)
{
    if (!root)
    {
        *depth = 0;
        return true;
    }

    int left, right;
    if (IsBalanced(root->left, &left) && IsBalanced(root->right, &right))
    {
        if (abs(left - right) <= 1)
        {
            *depth = max(left, right) + 1;
            return true;
        }
    }
    return false;
}
bool IsBalanced_Solution(TreeNode *pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}
// 解1 利用上题求树的深度的解，通过判断深度差判定是否是平衡树，缺点是会有重复访问
// int TreeDepth(TreeNode *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     int left = TreeDepth(root->left);
//     int right = TreeDepth(root->right);
//     return max(left, right) + 1;
// }
// bool IsBalanced_Solution(TreeNode *pRoot)
// {
//     if (!pRoot)
//     {
//         return true;
//     }
//     int left = TreeDepth(pRoot->left);
//     int right = TreeDepth(pRoot->right);
//     if (abs(left - right) > 1)
//     {
//         return false;
//     }
//     return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
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
    cout<<IsBalanced_Solution(root)<<endl;
    return 0;
}