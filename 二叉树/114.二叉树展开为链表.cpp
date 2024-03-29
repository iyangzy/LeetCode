#include <iostream>
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
void flatten(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    flatten(root->left);
    flatten(root->right);

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = nullptr;
    root->right = left;

    TreeNode *p = root;
    while (p->right)
    {
        p = p->right;
    }
    p->right = right;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    flatten(root);
    while (root)
    {
        cout << root->val << endl;
        root = root->right;
    }

    return 0;
}