#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(1, k, n, cur, ans);
        return ans;
    }

    void backtrack(int start, int k, int n, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (k == 0 || n <= 0)
            return;
        for (int i = start; i <= 9; ++i)
        {
            cur.push_back(i);
            backtrack(i + 1, k - 1, n - i, cur, ans);
            cur.pop_back();
        }
    }
};