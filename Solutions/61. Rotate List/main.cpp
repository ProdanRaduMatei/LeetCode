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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int length = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            ++length;
        }
        tail->next = head;
        k = k % length;
        int stepsToNewHead = length - k;
        ListNode *newTail = tail;
        while (stepsToNewHead--)
            newTail = newTail->next;
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};