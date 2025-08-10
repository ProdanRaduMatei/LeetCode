#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(1, n, k, path, res);
        return res;
    }

private:
    void backtrack(int start, int n, int k, vector<int> &path, vector<vector<int>> &res)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n - (k - path.size()) + 1; ++i)
        {
            path.push_back(i);
            backtrack(i + 1, n, k, path, res);
            path.pop_back();
        }
    }
};