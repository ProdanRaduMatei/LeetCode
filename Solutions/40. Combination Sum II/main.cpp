#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &path, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, path, result);
            path.pop_back();
        }
    }
};