#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return build(1, n);
    }

private:
    vector<TreeNode *> build(int l, int r)
    {
        if (l > r)
            return {nullptr};
        vector<TreeNode *> res;
        for (int i = l; i <= r; i++)
        {
            vector<TreeNode *> leftTrees = build(l, i - 1);
            vector<TreeNode *> rightTrees = build(i + 1, r);
            for (TreeNode *left : leftTrees)
            {
                for (TreeNode *right : rightTrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};