#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
vector<int> printListFromTailToHead(ListNode *head)
{
    vector<int> res;
    while (head)
    {
        res.push_back(head->val);
        head = head->next;
    }
    //反转vector有两种方式
    // 第一种
    // return {res.rbegin(),res.rend()};
    // 第二种
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    ListNode *root = new ListNode(67);
    root->next = new ListNode(0);
    root->next->next = new ListNode(24);
    root->next->next->next = new ListNode(58);
    vector<int> res = printListFromTailToHead(root);
    for (auto v : res)
    {
        cout << v << "->";
    }
    return 0;
}