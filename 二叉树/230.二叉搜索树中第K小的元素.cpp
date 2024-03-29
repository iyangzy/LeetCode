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
// 分治法，性能没有借助栈的解法好，但算是一种通用解法，学习一下还是有必要的
int nodeCount(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    int n = nodeCount(root->left);
    if (n + 1 == k)
    {
        return root->val;
    }
    else if (n + 1 < k)
    {
        return kthSmallest(root->right, k - n - 1);
    }
    else
    {
        return kthSmallest(root->left, k);
    }
}
// 中序遍历是最好想的，但是肯定不是最优解，这里借助栈+迭代，这个方法不好想
// int kthSmallest(TreeNode *root, int k)
// {
//     stack<TreeNode *> node;
//     while (true)
//     {
//         while (root)
//         {
//             node.push(root);
//             root = root->left;
//         }
//         root = node.top();
//         node.pop();
//         if (--k == 0)
//         {
//             return root->val;
//         }
//         root = root->right;
//     }
// }
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << kthSmallest(root, 1) << endl;
    return 0;
}