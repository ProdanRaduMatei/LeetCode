#include <limits.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int minDiff = INT_MAX;
    int prevVal = -1;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (prevVal != -1)
            minDiff = min(minDiff, root->val - prevVal);
        prevVal = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return minDiff;
    }
};