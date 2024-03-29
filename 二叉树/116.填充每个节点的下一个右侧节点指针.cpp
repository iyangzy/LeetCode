#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
void connentTwoNode(Node *m,Node *n)
{
    if (m==nullptr || n==nullptr)
    {
        return;
    }
    m->next = n;

    connentTwoNode(m->left,m->right);
    connentTwoNode(n->left,n->right);
    connentTwoNode(m->right,n->left);
}
Node *connect(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    connentTwoNode(root->left,root->right);
    return root;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *res = connect(root);
    return 0;
}