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
// 我一开始的思路就dfs，书上的解法更简单，如下
int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << maxDepth(root) << endl;
    return 0;
}