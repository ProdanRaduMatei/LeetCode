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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getHeight(TreeNode *node, bool isLeft)
    {
        int height = 0;
        while (node)
        {
            ++height;
            node = isLeft ? node->left : node->right;
        }
        return height;
    }
};