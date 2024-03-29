#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool recur(TreeNode *A, TreeNode *B)
{
    if (!B)
    {
        return true;
    }
    if (!A || A->val != B->val)
    {
        return false;
    }
    return recur(A->left, B->left) && recur(A->right, B->right);
}
bool isSubStructure(TreeNode *A, TreeNode *B)
{
    return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
}
TreeNode *createT1()
{
    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(4);
    r->right = new TreeNode(5);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(2);
    return r;
}
TreeNode *createT2()
{
    TreeNode *r = new TreeNode(4);
    r->left = new TreeNode(1);
    return r;
}
int main()
{
    cout << isSubStructure(createT1(), createT2()) << endl;
    return 0;
}