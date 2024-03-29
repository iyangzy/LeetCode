#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 翻转整个列表
ListNode *reverse(ListNode *head)
{
    if (head->next == nullptr)
    {
        return head;
    }
    ListNode *last = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}
// 翻转列表的前n个元素
ListNode *successor = nullptr;
ListNode *reverseN(ListNode *head, int n)
{
    if (n == 1)
    {
        successor = head->next;
        return head;
    }
    ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;
    return last;
}
// 翻转部分链表，从left到right
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == 1)
    {
        return reverseN(head, right);
    }
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
}
int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    p->next->next->next->next->next = nullptr;
    // ListNode *reverseList = reverse(p);
    // ListNode *reverseList = reverseN(p, 3);
    ListNode *reverseList = reverseBetween(p, 2, 4);
    while (reverseList)
    {
        cout << reverseList->val << "->";
        reverseList = reverseList->next;
    }
    cout << "NULL";
    return 0;
}