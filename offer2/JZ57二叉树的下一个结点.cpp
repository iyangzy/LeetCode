#include <iostream>
using namespace std;
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};
TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    TreeLinkNode *nextNdoe = nullptr;
    if (pNode->right)
    {
        TreeLinkNode *rightNode = pNode->right;
        while (rightNode->left)
        {
            rightNode = rightNode->left;
        }
        nextNdoe = rightNode;
    }
    else if (pNode->next)
    {
        TreeLinkNode *curNode = pNode;
        TreeLinkNode *parNode = pNode->next;
        while (parNode && curNode == parNode->right)
        {
            curNode = parNode;
            parNode = curNode->next;
        }
        nextNdoe = parNode;
    }
    return nextNdoe;
}
int main()
{
    return 0;
}