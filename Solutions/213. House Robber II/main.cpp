#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    int robLinear(vector<int> &nums, int left, int right)
    {
        int prev1 = 0, prev2 = 0;
        for (int i = left; i <= right; ++i)
        {
            int take = prev2 + nums[i];
            int skip = prev1;
            int cur = max(take, skip);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};