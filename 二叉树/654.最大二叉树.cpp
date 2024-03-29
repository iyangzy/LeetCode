#include <iostream>
#include <vector>
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
// 对原下面代码改进一下，但是没有提升，我XXXXXXXXX
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return new TreeNode(nums[0]);
    }
    if (nums.size() == 0)
    {
        return nullptr;
    }
    

    int len = nums.size();
    int maxValIndex = 0;
    for (int i = 1; i < len; i++)
    {
        if (nums[i] > nums[maxValIndex])
        {
            maxValIndex = i;
        }
    }
    TreeNode *root = new TreeNode(nums[maxValIndex]);
    if (maxValIndex > 0)
    {
        vector<int> left = {nums.begin(), nums.begin() + maxValIndex};
        root->left = constructMaximumBinaryTree(left);
    }
    else
    {
        root->left = nullptr;
    }
    if (maxValIndex < len)
    {
        vector<int> right = {nums.begin() + maxValIndex + 1, nums.end()};
        root->right = constructMaximumBinaryTree(right);
    }
    else
    {
        root->right = nullptr;
    }
    return root;
}
// TreeNode *constructMaximumBinaryTree(vector<int> &nums)
// {
//     if (nums.size() == 0)
//     {
//         return nullptr;
//     }

//     int len = nums.size();
//     int maxValIndex = 0;
//     for (int i = 1; i < len; i++)
//     {
//         if (nums[i] > nums[maxValIndex])
//         {
//             maxValIndex = i;
//         }
//     }
//     TreeNode *root = new TreeNode(nums[maxValIndex]);
//     vector<int> left;
//     vector<int> right;
//     if (maxValIndex > 0)
//     {
//         left = {nums.begin(), nums.begin() + maxValIndex};
//     }
//     else
//     {
//         left = {};
//     }
//     if (maxValIndex < len)
//     {
//         right = {nums.begin() + maxValIndex + 1, nums.end()};
//     }
//     else
//     {
//         right = {};
//     }
//     root->left = constructMaximumBinaryTree(left);
//     root->right = constructMaximumBinaryTree(right);
//     return root;
// }

int main()
{
    vector<int> v = {3,2,1};
    TreeNode *res = constructMaximumBinaryTree(v);
    return 0;
}