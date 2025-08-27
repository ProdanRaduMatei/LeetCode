#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1 || k == 0)
            return 0;
        if (k >= n / 2)
        {
            int ans = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            return ans;
        }
        const int NEG = -1e9;
        vector<int> hold(k + 1, NEG), cash(k + 1, 0);
        for (int p : prices)
            for (int t = 1; t <= k; ++t)
            {
                hold[t] = max(hold[t], cash[t - 1] - p);
                cash[t] = max(cash[t], hold[t] + p);
            }
        return cash[k];
    }
};