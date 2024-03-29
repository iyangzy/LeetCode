#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 双端队列deque
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<vector<int>> level = {};
    deque<TreeNode *> q;
    q.push_back(root);
    bool re = false;
    while (!q.empty())
    {
        vector<int> level2 = {};
        int currSize = q.size();
        TreeNode *t;
        for (int i = 0; i < currSize; i++)
        {
            if (!q.front())
            {
                continue;
            }

            if (!re) // 当前遍历到奇数层
            {
                t = q.front();
                q.pop_front();
                if (t->left)
                {
                    q.push_back(t->left);
                }
                if (t->right)
                {
                    q.push_back(t->right);
                }
            }
            else
            {
                t = q.back();
                q.pop_back();
                if (t->right)// 这里要先放右子树
                {
                    q.push_front(t->right);
                }
                if (t->left)
                {
                    q.push_front(t->left);
                }
                
            }
            level2.push_back(t->val);
        }
        re = !re;
        level.push_back(level2);
    }
    return level;
}
// 利用reverse函数，简单，效率低
// vector<vector<int>> levelOrder(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return {};
//     }

//     vector<vector<int>> level = {};
//     queue<TreeNode *> q;
//     q.push(root);
//     bool re = false;
//     while (!q.empty())
//     {
//         vector<int> level2 = {};
//         int currSize = q.size();
//         for (int i = 0; i < currSize; i++)
//         {
//             TreeNode *t = q.front();
//             q.pop();
//             if (!t)
//             {
//                 continue;
//             }
//             level2.push_back(t->val);
//             if (t->left)
//             {
//                 q.push(t->left);
//             }
//             if (t->right)
//             {
//                 q.push(t->right);
//             }

//         }
//         if (re)
//         {
//             reverse(level2.begin(),level2.end());
//         }
//         re = !re;
//         level.push_back(level2);
//     }
//     return level;
// }
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
    r->right->left->left = new TreeNode(10);
    r->right->left->right = new TreeNode(11);
    r->right->left->left->left = new TreeNode(4);
    r->right->left->left->right = new TreeNode(5);
    vector<vector<int>> re = levelOrder(r);
    return 0;
}