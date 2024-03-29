#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 单调栈，逆序遍历搜索树的后序遍历
bool verifyPostorder(vector<int> &postorder)
{
    stack<int> s;
    int root = INT_MAX;
    for (int i = postorder.size() - 1; i >= 0; i--)
    {
        if (postorder[i] > root)
        {
            return false;
        }
        while (!s.empty() && postorder[i] < s.top())
        {
            root = s.top();
            s.pop();
        }
        s.push(postorder[i]);
    }
    return true;
}
// 没有思路，书上的思路，递归
// bool verifyPostorder(vector<int> &postorder)
// {
//     if (postorder.size() == 0)
//     {
//         return true;
//     }

//     int length = postorder.size();
//     int root = postorder[length - 1];

//     int i = 0;
//     for (; i < length - 1; i++)
//     {
//         if (postorder[i] > root)
//         {
//             break;
//         }
//     }

//     int j = i;
//     for (; j < length - 1; j++)
//     {
//         if (postorder[j] < root)
//         {
//             return false;
//         }
//     }

//     vector<int> leftTree(postorder.begin(), postorder.begin() + i);
//     vector<int> rightTree(postorder.begin() + i, postorder.end() - 1);// 右子树的开始位置和左子树的结束位置，用vector的迭代器的表示要注意
//     return verifyPostorder(leftTree) && verifyPostorder(rightTree);
// }
int main()
{
    vector<int> v = {1, 6, 3, 2, 5};
    cout << verifyPostorder(v) << endl;
    return 0;
}