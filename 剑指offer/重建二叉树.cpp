#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int>::iterator iter;
//利用vector的迭代器，优点代码简洁，空间占用少，但需新建一个函数；使用了find函数，代替了for循环，auto的类型是迭代器类型
// TreeNode *recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd)
// {
//     if (inEnd == inBegin)
//         return NULL;
//     TreeNode *cur = new TreeNode(*preBegin); //这里要用*获取它的值
//     auto root = find(inBegin, inEnd, *preBegin);
//     cur->left = recursionBuild(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
//     cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
//     return cur;
// }
// TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
// {
//     return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
// }

// 最基本的前序、中序建树，因为不太会用vector容器的原因，性能并不好
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size()==0 || inorder.size()==0)
    {
        return nullptr;
    }

    TreeNode * root = new TreeNode(preorder[0]);
    int i;
    for (i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == preorder[0])
        {
            break;
        }
    }
    vector<int> leftTreePre(preorder.begin()+1,preorder.begin()+i+1);
    vector<int> leftTreeIn(inorder.begin(),inorder.begin()+i);
    vector<int> rightTreePre(preorder.begin()+i+1,preorder.end());
    vector<int> rightTreeIn(inorder.begin()+i+1,inorder.end());
    root->left = buildTree(leftTreePre,leftTreeIn);
    root->right = buildTree(rightTreePre,rightTreeIn);
    return root;
}
//树的三种遍历，递归实现 + 层序遍历，队列实现
void preOrderTraverse(TreeNode *t)
{
    if (t)
    {
        cout << t->val << endl;
        preOrderTraverse(t->left);
        preOrderTraverse(t->right);
    }
}
void inOrderTraverse(TreeNode *t)
{
    if (t)
    {
        inOrderTraverse(t->left);
        cout << t->val << endl;
        inOrderTraverse(t->right);
    }
}
void postOrderTraverse(TreeNode *t)
{
    if (t)
    {
        postOrderTraverse(t->left);
        postOrderTraverse(t->right);
        cout << t->val << endl;
    }
}
void levelOrderTraverse(TreeNode *t)
{
    queue<TreeNode *> q;
    q.push(t);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        cout << temp->val << endl;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        q.pop();
    }
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *t = buildTree(preorder, inorder);
    cout << "----------前序遍历----------" << endl;
    preOrderTraverse(t);
    cout << "----------中序遍历----------" << endl;
    inOrderTraverse(t);
    cout << "----------后序遍历----------" << endl;
    postOrderTraverse(t);
    cout << "----------层序遍历----------" << endl;
    levelOrderTraverse(t);
    return 0;
}
