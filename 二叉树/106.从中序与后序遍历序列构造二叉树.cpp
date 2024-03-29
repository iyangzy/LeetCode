#include <iostream>
#include <vector>
#include <algorithm>
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
// 借助vector的迭代器简化，就只函数定义会麻烦点
TreeNode *buildWithIter(vector<int>::iterator inBegin, vector<int>::iterator inEnd, vector<int>::iterator postBegin, vector<int>::iterator postEnd)
{
    if (inBegin == inEnd)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(*(postEnd-1));// 这里解引用的时候要注意，end指向的是最后一个元素的下一个位置，直接解引用为空
    auto rootIter = find(inBegin, inEnd, *(postEnd-1));
    root->left = buildWithIter(inBegin, rootIter, postBegin, postBegin + (rootIter - inBegin));
    root->right = buildWithIter(rootIter + 1, inEnd, postBegin + (rootIter - inBegin), postEnd - 1);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildWithIter(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}
// 这是最原始的写法，性能并不好
// TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
// {
//     if (inorder.size() == 0 || postorder.size() == 0)
//     {
//         return nullptr;
//     }
//     int last = postorder[postorder.size() - 1];
//     TreeNode *root = new TreeNode(last);
//     int i = 0;
//     for (; i < inorder.size(); i++)
//     {
//         if (inorder[i] == last)
//         {
//             break;
//         }
//     }
//     vector<int> inoderLeft = {inorder.begin(), inorder.begin() + i};
//     vector<int> inorderRight = {inorder.begin() + i + 1, inorder.end()};
//     vector<int> postLeft = {postorder.begin(), postorder.begin() + i};
//     vector<int> postRight = {postorder.begin() + i, postorder.end() - 1};
//     root->left = buildTree(inoderLeft, postLeft);
//     root->right = buildTree(inorderRight, postRight);
//     return root;
// }
int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *res = buildTree(inorder, postorder);
    return 0;
}