#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<string> splitString(string data)
{
    vector<string> v;
    int i = 0;
    while (i < data.length())
    {
        string val = "";
        while (i < data.length() && data[i] != ',')
        {
            val.push_back(data[i]);
            i++;
        }
        i++;
        v.push_back(val);
    }
    return v;
}
// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "[]";
    }

    string s = "[";

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (t != nullptr)
        {
            s.append(to_string(t->val) + ",");
            // s += to_string(t->val) + ",";
            q.push(t->left);
            q.push(t->right);
        }
        else
        {
            s.append("null,");
            // s += "null,";
        }
    }
    s.at(s.length() - 1) = ']';
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data == "[]")
    {
        return nullptr;
    }

    data = data.substr(1, data.length() - 2);
    vector<string> nodes = splitString(data);
    TreeNode *root = new TreeNode(atoi(nodes[0].c_str()));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (nodes[i] != "null")
        {
            t->left = new TreeNode(atoi(nodes[i].c_str()));
            q.push(t->left);
        }
        i++;
        if (nodes[i] != "null")
        {
            t->right = new TreeNode(atoi(nodes[i].c_str()));
            q.push(t->right);
        }
        i++;
    }
    return root;
}
int main()
{
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);
    cout << serialize(r) << endl;
    TreeNode *re = deserialize(serialize(r));
    return 0;
}