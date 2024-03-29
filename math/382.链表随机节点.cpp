#include <iostream>
#include <vector>
#include<time.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *node) : val(x), next(node){};
};
class Solution
{
public:
    ListNode *list;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        list = head;
        srand((int)time(NULL));
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *p = list;
        int i=0, res=0;
        while (p)
        {
            if(rand()%(++i)==0)
            {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next = new ListNode(3);
    Solution *solution = new Solution(head);
    cout << solution->getRandom() << endl;
    return 0;
}