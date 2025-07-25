#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};