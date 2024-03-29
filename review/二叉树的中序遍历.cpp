#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
// 迭代法遍历
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> inOrderStack;
    vector<int> res;

    TreeNode *p = root;
    while(p || !inOrderStack.empty())
    {
        while(p)
        {
            inOrderStack.push(p);
            p = p->left;
        }
        p = inOrderStack.top();
        inOrderStack.pop();
        res.push_back(p->val);
        p = p->right;
    }
    return res;
}