#include <iostream>
#include <vector>

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;
            ListNode *second = first->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
        }
        return dummy.next;
    }
};