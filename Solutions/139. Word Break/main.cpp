#include <iostream>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        int Lmin = INT_MAX, Lmax = 0;
        for (auto &w : wordDict)
        {
            Lmin = min(Lmin, (int)w.size());
            Lmax = max(Lmax, (int)w.size());
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int len = Lmin; len <= Lmax; ++len)
            {
                if (i - len < 0)
                    break;
                if (!dp[i - len])
                    continue;
                if (dict.count(s.substr(i - len, len)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};