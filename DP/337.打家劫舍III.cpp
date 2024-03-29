#include <iostream>
#include <vector>
#include <unordered_map>
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
unordered_map<TreeNode *, int> memo;
int rob(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (memo.find(root) != memo.end())
    {
        return memo[root];
    }

    int robIt = root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0)+(root->right ? rob(root->right->left) + rob(root->right->right) : 0);
    int notRob = rob(root->left)+rob(root->right);
    int res = max(robIt,notRob);
    memo[root] = res;
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << rob(root) << endl;
    return 0;
}