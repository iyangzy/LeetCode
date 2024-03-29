#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void ConvertNode(TreeNode *pNode, TreeNode **pLastNodeInList)
{
    if (pNode == nullptr)
    {
        return;
    }

    TreeNode *pCurrent = pNode;
    if (pCurrent->left != nullptr)
    {
        ConvertNode(pCurrent->left, pLastNodeInList);
    }

    pCurrent->left = *pLastNodeInList;
    if (*pLastNodeInList != nullptr)
    {
        (*pLastNodeInList)->right = pCurrent;
    }

    *pLastNodeInList = pCurrent;

    if (pCurrent->right != nullptr)
    {
        ConvertNode(pCurrent->right, pLastNodeInList);
    }
}
TreeNode *Convert(TreeNode *pRootOfTree)
{
    TreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    TreeNode *pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->left != nullptr)
    {
        pHeadOfList = pHeadOfList->left;
    }
    return pHeadOfList;
}
int main()
{
}