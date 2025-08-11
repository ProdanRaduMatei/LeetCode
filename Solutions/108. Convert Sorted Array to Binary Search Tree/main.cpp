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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, (int)nums.size() - 1);
    }

private:
    TreeNode *build(const vector<int> &a, int L, int R)
    {
        if (L > R)
            return nullptr;
        int mid = L + (R - L) / 2;
        TreeNode *root = new TreeNode(a[mid]);
        root->left = build(a, L, mid - 1);
        root->right = build(a, mid + 1, R);
        return root;
    }
};