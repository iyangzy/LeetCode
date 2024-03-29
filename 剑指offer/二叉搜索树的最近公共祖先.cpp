#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 前提是本题明确说明是二叉搜索树
// 一次遍历，力扣官解
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *ancetor = root;
    while(true)
    {
        if (p->val > ancetor->val && q->val > ancetor->val)
        {
            ancetor = ancetor->right;
        }
        else if (p->val < ancetor->val && q->val < ancetor->val)
        {
            ancetor = ancetor->left;
        }
        else
        {
            break;
        }
    }
    return ancetor;
}
int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    TreeNode *ancetor = lowestCommonAncestor(root,new TreeNode(2),new TreeNode(4));
    cout<<ancetor->val<<endl;
    return 0;
}