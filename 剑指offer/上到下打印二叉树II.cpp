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
vector<vector<int>> levelOrder(TreeNode *root)
{
    // if (root == nullptr) // 这里debug电脑直接卡死，what？？？？？？有什么问题吗
    // {
    //     return {};
    // }

    vector<vector<int>> level2 = {};
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level = {};
        int curr = q.size(); // 早知道有这个函数，就不用再建一个辅助队列了
        for (int i = 0; i < curr; i++)
        {
            TreeNode *t = q.front();
            q.pop();// 如果root是空，不弹出就走continue会死循环，因为root一直在里面
            if (!t)
            {
                continue;
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
        level2.push_back(level);
    }
    return level2;
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
    vector<vector<int>> re = levelOrder(r);
    return 0;
}