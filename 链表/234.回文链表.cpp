#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};
ListNode *reverse(ListNode *a)
{
    if (!a || !a->next)
    {
        return a;
    }
    ListNode *last = reverse(a->next);
    a->next->next = a;
    a->next = nullptr;
    return last;
}
// 快慢指针
bool isPalindrome(ListNode *head)
{
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) // 因为fast要走两步，在节点总数是奇数和偶数的情况下是不一样的，所以有两个判断标准
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 当链表节点总数为奇数时，没走两步，最后一步肯定是尾结点，slow指向的是中间节点没错，但是此时的中间节点不用来判断回文
    if (fast)
    {
        slow = slow->next;
    }

    ListNode *p = reverse(slow);
    while (p)
    {
        if (head->val != p->val)
        {
            return false;
        }
        head = head->next;
        p = p->next;
    }
    return true;
}
int main()
{
    ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    p->next = nullptr;
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(2);
    // p->next->next->next->next = new ListNode(1);
    // p->next->next->next->next->next = nullptr;
    cout << isPalindrome(p) << endl;
    return 0;
}