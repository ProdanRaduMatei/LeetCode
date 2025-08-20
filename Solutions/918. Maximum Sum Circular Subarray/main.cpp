#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        long long total = 0;
        long long curMax = 0, bestMax = LLONG_MIN;
        long long curMin = 0, bestMin = LLONG_MAX;
        for (int x : nums)
        {
            total += x;
            curMax = max<long long>(x, curMax + x);
            bestMax = max(bestMax, curMax);
            curMin = min<long long>(x, curMin + x);
            bestMin = min(bestMin, curMin);
        }
        if (bestMax < 0)
            return (int)bestMax;
        return (int)max(bestMax, total - bestMin);
    }
};