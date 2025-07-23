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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (count >= k)
        {
            ListNode *curr = prev->next;
            ListNode *next = curr->next;
            for (int i = 1; i < k; ++i)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy.next;
    }
};