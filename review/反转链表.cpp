#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
// 递归法
ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;// 这里是return的head，不是nullptr，不是nullptr，不是nullptr
    }

    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
// 迭代法
ListNode *reverseList(ListNode *head)
{
    ListNode *re = new ListNode(-1);
    re->next = nullptr;

    ListNode *p;
    while (head)
    {
        p = head;
        head = head->next;

        p->next = re->next;
        re->next = p;
    }
    return re->next;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode *reHead = reverseList(head);
    while (reHead)
    {
        cout << reHead->val << "->";
        reHead = reHead->next;
    }
    return 0;
}