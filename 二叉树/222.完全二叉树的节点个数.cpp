#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool exists(TreeNode *root, int level, int k)
{
    int bits = 1 << (level - 1);
    TreeNode *node = root;
    while (node && bits > 0)
    {
        if (!(bits & k))
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != nullptr;
}
int countNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int level = 0;
    TreeNode *node = root;
    while (node->left)
    {
        level++;
        node = node->left;
    }
    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high)
    {
        int mid = (high - low + 1) / 2 + low;
        if (exists(root, level, mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << countNodes(root) << endl;
    return 0;
}