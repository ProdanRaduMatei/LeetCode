#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = 0;
        for (ListNode *p = head; p; p = p->next)
            n++;
        return buildBST(head, n);
    }

private:
    TreeNode *buildBST(ListNode *&head, int n)
    {
        if (n <= 0)
            return nullptr;
        TreeNode *left = buildBST(head, n / 2);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = buildBST(head, n - n / 2 - 1);
        return root;
    }
};