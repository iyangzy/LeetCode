#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 本题只说明是二叉树，所有节点的值都是唯一的。
// 递归+DFS
TreeNode *ancetor;
bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return false;
    }
    bool lson = dfs(root->left, p, q);
    bool rson = dfs(root->right, p, q);
    if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
    {
        ancetor = root;
    }
    return lson || rson || (root->val == p->val || root->val == q->val);
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    dfs(root, p, q);
    return ancetor;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode *ancetor = lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
    cout << ancetor->val << endl;
    return 0;
}