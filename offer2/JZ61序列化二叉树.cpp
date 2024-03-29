#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
char *Serialize(TreeNode *root)
{
    string str = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            if (t == nullptr)
            {
                str.push_back('#');
            }
            else
            {
                str.append(to_string(t->val));
                q.push(t->left);
                q.push(t->right);
            }
            str.push_back('!');
        }
    }
    char *res = new char[str.length() + 1];
    strcpy(res, str.c_str());
    return res;
}
TreeNode *Deserialize(char *str)
{
    if (str == nullptr || str[0] == '#')
    {
        return nullptr;
    }

    string s = str;
    TreeNode *root = new TreeNode(atoi(s.c_str()));
    s = s.substr(s.find_first_of('!') + 1);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty() && !s.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (s[0] == '#')
        {
            t->left = nullptr;
            s = s.substr(2);
        }
        else
        {
            t->left = new TreeNode(atoi(s.c_str()));
            s = s.substr(s.find_first_of('!') + 1);
            q.push(t->left);
        }
        if (s[0] == '#')
        {
            t->right = nullptr;
            s = s.substr(2);
        }
        else
        {
            t->right = new TreeNode(atoi(s.c_str()));
            s = s.substr(s.find_first_of('!') + 1);
            q.push(t->right);
        }
    }
    return root;
}
int main()
{
    TreeNode *root = nullptr;
    TreeNode *reBuild = Deserialize(Serialize(root));
    return 0;
}