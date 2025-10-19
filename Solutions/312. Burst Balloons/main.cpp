#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        vector<int> a;
        a.reserve(nums.size() + 2);
        a.push_back(1);
        for (int x : nums)
            if (x != 0)
                a.push_back(x);
        a.push_back(1);
        int m = (int)a.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; ++len)
        {
            for (int l = 0; l + len < m; ++l)
            {
                int r = l + len;
                int best = 0;
                for (int k = l + 1; k < r; ++k)
                {
                    best = max(best, dp[l][k] + a[l] * a[k] * a[r] + dp[k][r]);
                }
                dp[l][r] = best;
            }
        }
        return dp[0][m - 1];
    }
};