#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// DFS
vector<vector<int>> paths;
vector<int> path;
void recur(TreeNode *t, int sum)
{
    if (t==nullptr)
    {
        return;
    }
    sum -= t->val;
    path.push_back(t->val);
    if (sum == 0 && t->left == nullptr && t->right == nullptr)
    {   
        // vector<int> p = path;
        paths.push_back(path);// 这里可以直接将path添加到结果里
    }
    recur(t->left, sum);
    recur(t->right, sum);
    path.pop_back();// 回溯
}
vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    recur(root,sum);
    return paths;
}
int main()
{
    TreeNode *r = new TreeNode(5);
    r->left = new TreeNode(4);
    r->right = new TreeNode(8);
    r->left->left = new TreeNode(11);
    r->right->left = new TreeNode(13);
    r->right->right = new TreeNode(4);
    r->left->left->left = new TreeNode(7);
    r->left->left->right = new TreeNode(2);
    r->right->right->left = new TreeNode(5);
    r->right->right->right = new TreeNode(1);
    TreeNode *t;
    vector<vector<int>> re = pathSum(r,22);
    return 0;
}