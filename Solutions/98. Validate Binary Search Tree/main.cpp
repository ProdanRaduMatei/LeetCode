#include <limits.h>

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
    bool helper(TreeNode *node, long long minVal, long long maxVal)
    {
        if (!node)
            return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        return helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};