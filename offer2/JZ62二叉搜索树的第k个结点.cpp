#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *kth = nullptr;
void inOrder(TreeNode *root, int &k)
{
    if (root)
    {
        inOrder(root->left, k);
        if (--k == 0)
        {
            kth = root;
            return;
        }
        inOrder(root->right, k);
    }
}
TreeNode *KthNode(TreeNode *pRoot, int k)
{
    inOrder(pRoot, k);
    return kth;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    TreeNode *kth = KthNode(root, 3);
    cout << kth->val << endl;
    return 0;
}