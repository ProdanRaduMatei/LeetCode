#include <cstddef>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        int n = 0;
        for (ListNode *p = head; p; p = p->next)
            ++n;
        ListNode dummy(0, head);
        for (int sz = 1; sz < n; sz <<= 1)
        {
            ListNode *cur = dummy.next;
            ListNode *tail = &dummy;
            while (cur)
            {
                ListNode *left = cur;
                ListNode *right = split(left, sz);
                cur = split(right, sz);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }

private:
    static ListNode *split(ListNode *head, int n)
    {
        while (head && --n)
            head = head->next;
        if (!head)
            return nullptr;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    static ListNode *merge(ListNode *l1, ListNode *l2, ListNode *tail)
    {
        ListNode *cur = tail;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next)
            cur = cur->next;
        return cur;
    }
};