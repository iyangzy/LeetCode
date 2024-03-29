#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<vector<int>> path;
void recu(TreeNode *root, vector<int> nodes, int expec)
{
    if (!root || expec < 0)
    {
        return;
    }

    nodes.push_back(root->val);
    expec -= root->val;
    if (expec == 0)
    {
        if (!root->left && !root->right)
        {
            path.push_back(nodes);
        }
        return;
    }

    recu(root->left, nodes, expec);
    recu(root->right, nodes, expec);
}
vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
{
    if (!root || root->val > expectNumber)
    {
        return {};
    }

    vector<int> nodes;
    recu(root, nodes, expectNumber);

    return path;
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    vector<vector<int>> res = FindPath(root, 15);
    cout << res.size() << endl;
    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << "->";
        }
        cout << endl;
    }
    return 0;
}
