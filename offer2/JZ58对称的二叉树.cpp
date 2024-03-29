#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool recur(TreeNode *leftTree, TreeNode *rightTree)
{
    if (leftTree && rightTree)
    {
        if (leftTree->val == rightTree->val)
        {
            return recur(leftTree->left, rightTree->right) && recur(leftTree->right, rightTree->left);
        }
        return false;
    }
    else if (!leftTree && !rightTree)
    {
        return true;
    }
    return false;
}
bool isSymmetrical(TreeNode *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    return recur(pRoot->left, pRoot->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    cout << isSymmetrical(root) << endl;
    return 0;
}
