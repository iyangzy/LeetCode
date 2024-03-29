#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 利用队列的常规解法,BFS
vector<int> levelOrder(TreeNode *root)
{
    // if (root == nullptr)// 这里debug电脑直接卡死，what？？？？？？，有什么问题吗
    // {
    //     return {};
    // }

    vector<int> level = {};
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (!t) // 可以在这里判空，也可以在函数开头，像注释的那样，不过这样感觉更好一点
        {
            break;
        }

        level.push_back(t->val);
        
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
    return level;
}
int main()
{
    TreeNode *r = new TreeNode(3);
    TreeNode *t;
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    // r->left->left = new TreeNode(1);
    // r->left->right = new TreeNode(3);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    vector<int> re = levelOrder(r);
    for (vector<int>::iterator iter = re.begin(); iter < re.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}