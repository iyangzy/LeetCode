#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    
    ListNode *slow = head, *fast = head;
    while (fast)
    {
        if (fast->val != slow->val)
        {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;
    return head;
}
int main()
{
    ListNode *head;
    ListNode *newList = deleteDuplicates(head);
    while (newList)
    {
        cout<<newList->val<<"->";
        newList = newList->next;
    }
    return 0;
}