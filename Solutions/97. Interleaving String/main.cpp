#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        vector<char> dp(n2 + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n2; ++j)
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        for (int i = 1; i <= n1; ++i)
        {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n2; ++j)
            {
                bool fromTop = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                bool fromLeft = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[j] = fromTop || fromLeft;
            }
        }
        return dp[n2];
    }
};