#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLen = INT_MAX;
        int sum = 0, start = 0;
        for (int end = 0; end < n; ++end)
        {
            sum += nums[end];
            while (sum >= target)
            {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};