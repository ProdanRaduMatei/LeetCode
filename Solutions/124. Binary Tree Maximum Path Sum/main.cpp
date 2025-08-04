#include <climits>
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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxSum;
    }

private:
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int leftGain = max(0, dfs(node->left));
        int rightGain = max(0, dfs(node->right));
        int currentPathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPathSum);
        return node->val + max(leftGain, rightGain);
    }
};