#include <iostream>
#include <__stddef_null.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left; // Both are in left subtree
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right; // Both are in right subtree
            }
            else
            {
                return root; // Split point → LCA found
            }
        }
        return nullptr;
    }
};