#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 层序遍历
int strToInt(string str)
{
    stringstream ss;
    int res;
    ss << str;
    ss >> res;
    return res;
}
// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string str = "";
    string sep = ",";
    if (!root)
    {
        return str;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();

        if (!t)
        {
            str.append("#");
        }
        else
        {
            str.append(to_string(t->val));
            q.push(t->left);
            q.push(t->right);
        }
        str.append(sep);
    }
    return str;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.length() == 0)
    {
        return nullptr;
    }

    int t = 0;
    vector<string> v;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] != ',')
        {
            continue;
        }
        v.push_back(data.substr(t, i - t));
        t = i + 1;
    }
    t = 0;
    TreeNode *root = new TreeNode(strToInt(v[t++]));
    queue<TreeNode*> q;
    q.push(root);
    while (t < v.size())
    {
        TreeNode *p = q.front();
        q.pop();
        if (v[t] == "#")
        {
            p->left = nullptr;
        }
        else
        {
            p->left = new TreeNode(strToInt(v[t]));
            q.push(p->left);
        }
        t++;
        if (v[t] == "#")
        {
            p->right = nullptr;
        }
        else
        {
            p->right = new TreeNode(strToInt(v[t]));
            q.push(p->right);
        }
        t++;
    }
    return root;
}
int main()
{
    TreeNode *root;

    string str = serialize(root);
    TreeNode *res = deserialize(str);
    return 0;
}