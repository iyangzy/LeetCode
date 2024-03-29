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
// 后序遍历，并且在过程中记录每个节点的深度
bool isBalanced(TreeNode *root, int *depth)
{
    if (!root)
    {
        *depth = 0;
        return true;
    }

    int left, right;
    if (isBalanced(root->left, &left) && isBalanced(root->right, &right))
    {
        int diff = fabs(left - right);
        if (diff <= 1)
        {
            *depth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}
bool isBalanced(TreeNode *root)
{
    int d = 0;
    return isBalanced(root, &d);
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << isBalanced(root) << endl;
    return 0;
}