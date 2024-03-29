#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.empty() || vin.empty())
    {
        return nullptr;
    }
    int t = pre[0];

    TreeNode *root = new TreeNode(pre[0]);
    int i = 0;
    for (; vin[i] != pre[0]; i++)
        ;
    root->left = reConstructBinaryTree({pre.begin() + 1, pre.begin() + i + 1}, {vin.begin(), vin.begin() + i});
    root->right = reConstructBinaryTree({pre.begin() + i + 1, pre.end()}, {vin.begin() + i + 1, vin.end()});
    return root;
}
void inOrderTraverse(TreeNode *root)
{
    if (root)
    {
        inOrderTraverse(root->left);
        cout << root->val << endl;
        inOrderTraverse(root->right);
    }
}
int main()
{
    vector<int> pre = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vin = {3, 2, 4, 1, 6, 5, 7};
    TreeNode *root = reConstructBinaryTree(pre, vin);
    inOrderTraverse(root);
    return 0;
}