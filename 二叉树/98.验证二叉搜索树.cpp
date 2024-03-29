#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 中序遍历，这种中序遍历的方式要学一下
bool isValidBST(TreeNode *root)
{
    stack<TreeNode *> st;
    int inOrder = INT64_MIN - 1;

    while (!st.empty() || root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (root->val <= inOrder)
        {
            return false;
        }
        inOrder = root->val;
        root = root->right;
    }
    return true;
}
// 递归
// bool helper(TreeNode *root, long long low, long long high)
// {
//     if (!root)
//     {
//         return true;
//     }
//     if (root->val <= low || root->val >= high)
//     {
//         return false;
//     }
//     return helper(root->left, low, root->val) && helper(root->right, root->val, high);
// }
// bool isValidBST(TreeNode *root)
// {
//     return helper(root, INT64_MIN, INT64_MAX);
// }
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << isValidBST(root) << endl;
    return 0;
}