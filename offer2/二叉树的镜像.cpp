#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
// 进阶
TreeNode *Mirror(TreeNode *pRoot)
{
   if (!pRoot)
   {
       return pRoot;
   }

   TreeNode *t = pRoot->left;

   pRoot->left = Mirror(pRoot->right);
   pRoot->right = Mirror(t);
   return pRoot;
}
// 基本解法
// TreeNode *Mirror(TreeNode *pRoot)
// {
//    if (!pRoot)
//    {
//        return pRoot;
//    }

//    TreeNode *t = pRoot->left;
//    pRoot->left = pRoot->right;
//    pRoot->right = t;

//    Mirror(pRoot->left);
//    Mirror(pRoot->right);
//    return pRoot;
// }
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    TreeNode *mirrorTree = Mirror(root);
    return 0;
}
