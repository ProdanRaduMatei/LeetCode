#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if (len <= 2)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i)
        {
            if (isPal[0][i])
                dp[i] = 0;
            else
            {
                for (int j = 0; j < i; ++j)
                    if (isPal[j + 1][i])
                        dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
};