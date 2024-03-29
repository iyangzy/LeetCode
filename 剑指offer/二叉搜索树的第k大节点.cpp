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
int res, target;
void reInOrder(TreeNode *root)
{
    if (root)
    {
        reInOrder(root->right);
        if (target == 0) // 这个提前返回的策略自己没有想好
        {
            return;
        }
        if (--target == 0)
        {
            res = root->val;
        }
        reInOrder(root->left);
    }
}
int kthLargest(TreeNode *root, int k)
{
    target = k;
    reInOrder(root);
    return res;
}
// 中序遍历我自己的版本
// vector<int> re;
// void inOrder(TreeNode *root)
// {
//     if (root)
//     {
//         inOrder(root->right);
//         re.push_back(root->val);
//         inOrder(root->left);
//     }
// }
// int kthLargest(TreeNode *root, int k)
// {
//     inOrder(root);
//     return re[k-1];
// }
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << kthLargest(root, 1) << endl;
    return 0;
}