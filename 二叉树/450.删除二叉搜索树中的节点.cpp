#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *getMin(TreeNode *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val == key)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        if (root->left == nullptr)
        {
            return root->right;
        }
        if (root->right == nullptr)
        {
            return root->left;
        }
        TreeNode *minNode = getMin(root->right);// 这里只是交换节点的值，并没有交换节点本身
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }

    return root;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    TreeNode *res = deleteNode(root, 7);
    return 0;
}