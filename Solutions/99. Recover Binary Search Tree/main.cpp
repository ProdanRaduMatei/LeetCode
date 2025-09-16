#include <iostream>

using namespace std;

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode *cur = root;

        while (cur)
        {
            if (!cur->left)
            {
                if (prev && cur->val < prev->val)
                {
                    if (!first)
                        first = prev;
                    second = cur;
                }
                prev = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode *pred = cur->left;
                while (pred->right && pred->right != cur)
                    pred = pred->right;
                if (!pred->right)
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pred->right = nullptr;
                    if (prev && cur->val < prev->val)
                    {
                        if (!first)
                            first = prev;
                        second = cur;
                    }
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};