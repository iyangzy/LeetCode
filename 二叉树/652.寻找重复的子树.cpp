#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 深搜+序列化
vector<TreeNode *> res;// 把函数参数定义成全局的，可以提升一点性能，前提是参数是取址使用
unordered_map<string, int> map;
string dfs(TreeNode *root)
{
    if (!root)
    {
        return "#";
    }

    string left = dfs(root->left);
    string right = dfs(root->right);
    string str = left + ',' + right + ',' + to_string(root->val); // 这里要加分隔符

    if (map[str] == 1)
    {
        res.push_back(root);
    }
    map[str]++;
    return str;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    dfs(root);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    vector<TreeNode *> res = findDuplicateSubtrees(root);
    for (vector<TreeNode *>::iterator iter = res.begin(); iter < res.end(); iter++)
    {
        cout << (*iter)->val << endl;
    }
    return 0;
}