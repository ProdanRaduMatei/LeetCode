#include <unordered_map>
#include <vector>

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
    unordered_map<int, int> inMap;
    int postIndex;

    TreeNode *buildTreeHelper(vector<int> &postorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->right = buildTreeHelper(postorder, inIndex + 1, inEnd);
        root->left = buildTreeHelper(postorder, inStart, inIndex - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;
        postIndex = postorder.size() - 1;
        return buildTreeHelper(postorder, 0, inorder.size() - 1);
    }
};