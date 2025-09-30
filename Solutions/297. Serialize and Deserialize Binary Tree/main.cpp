#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode *deserialize(string data)
    {
        queue<string> q = split(data, ',');
        return build(q);
    }

private:
    queue<string> split(const string &s, char delim)
    {
        queue<string> q;
        string token;
        stringstream ss(s);
        while (getline(ss, token, delim))
        {
            q.push(token);
        }
        return q;
    }

    TreeNode *build(queue<string> &q)
    {
        if (q.empty())
            return nullptr;
        string val = q.front();
        q.pop();
        if (val == "null" || val.empty())
            return nullptr;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = build(q);
        node->right = build(q);
        return node;
    }
};