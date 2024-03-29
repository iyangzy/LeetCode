#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
// 书上的解法，但是力扣上的题较原题做了改动，原题只是转换为双向链表，力扣要转换为循环双向链表
void recurInOrder(Node *node,Node **pLast)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left != nullptr)
    {
        recurInOrder(node->left,pLast);
    }
    
    node->left = *pLast;
    if (*pLast != nullptr)
    {
        (*pLast)->right = node;
    }
    *pLast = node;

    if (node->right != nullptr)
    {
        recurInOrder(node->right,pLast);
    }
}
Node *treeToDoublyList(Node *root)
{
    if (root == nullptr)// 空样例不要忘记处理
    {
        return root;
    }
    
    Node *pLast = nullptr;
    recurInOrder(root,&pLast);

    Node *pHead = pLast;
    while (pHead != nullptr && pHead->left != nullptr)
    {
        pHead = pHead->left;
    }
    // 首尾相连
    pHead->left = pLast;
    pLast->right = pHead;

    return pHead;
}
int main()
{
    Node *r = new Node(4);
    r->left = new Node(2);
    r->right = new Node(5);
    r->left->left = new Node(1);
    r->left->right = new Node(3);
    Node *t;
    Node *head = treeToDoublyList(t);
    return 0;
}