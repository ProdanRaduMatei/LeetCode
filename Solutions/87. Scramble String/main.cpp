#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (n != (int)s2.size())
            return false;
        if (s1 == s2)
            return true;
        vector<vector<vector<int8_t>>> dp(n, vector<vector<int8_t>>(n, vector<int8_t>(n + 1, -1)));
        return dfs(0, 0, n, s1, s2, dp);
    }

private:
    bool dfs(int i, int j, int len, const string &s1, const string &s2,
             vector<vector<vector<int8_t>>> &dp)
    {
        int8_t &memo = dp[i][j][len];
        if (memo != -1)
            return memo;
        if (s1.compare(i, len, s2, j, len) == 0)
        {
            memo = 1;
            return true;
        }
        int cnt[26] = {0};
        for (int k = 0; k < len; ++k)
        {
            ++cnt[s1[i + k] - 'a'];
            --cnt[s2[j + k] - 'a'];
        }
        for (int c = 0; c < 26; ++c)
        {
            if (cnt[c] != 0)
            {
                memo = 0;
                return false;
            }
        }
        for (int k = 1; k < len; ++k)
        {
            if (dfs(i, j, k, s1, s2, dp) && dfs(i + k, j + k, len - k, s1, s2, dp))
            {
                memo = 1;
                return true;
            }
            if (dfs(i, j + len - k, k, s1, s2, dp) && dfs(i + k, j, len - k, s1, s2, dp))
            {
                memo = 1;
                return true;
            }
        }
        memo = 0;
        return false;
    }
};