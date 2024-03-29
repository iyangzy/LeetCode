/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // C++11中用nullptr表示空指针，不要用NULL（存在二义性问题）
};
ListNode *removeDuplicateNodes(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    
    unordered_set<int> vis;
    ListNode *p = head;
    vis.insert(p->val);
    while (p->next)
    {
        if (vis.count(p->next->val) != 0)
        {
            ListNode *fast = p->next;
            while (fast->next && fast->next->val == p->next->val)
            {
                fast = fast->next;
            }
            p->next = fast->next;
            fast->next = nullptr;
            continue;
        }
        else
        {
            vis.insert(p->next->val);
        }
        p = p->next;
    }

    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(3);
    removeDuplicateNodes(head);
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
}