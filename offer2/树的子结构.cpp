#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
bool isEqual(TreeNode *t1, TreeNode *t2)
{
    if (!t2)
    {
        return true;
    }
    if (!t1 || t1->val != t2->val)
    {
        return false;
    }
    return isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
}
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (!pRoot2 || !pRoot1)
    {
        return false;
    }

    bool res = false;

    if (pRoot1->val == pRoot1->val)
    {
        res = isEqual(pRoot1, pRoot2);
    }
    if (!res)
    {
        res = HasSubtree(pRoot1->left, pRoot2);
    }
    if (!res)
    {
        res = HasSubtree(pRoot1->right, pRoot2);
    }
    return res;
}
int main()
{
}