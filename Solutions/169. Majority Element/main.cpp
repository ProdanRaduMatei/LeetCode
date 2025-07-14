#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int v = nums[0], p = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == v)
                ++p;
            else
            {
                if (p > 0)
                    --p;
                else
                {
                    v = nums[i];
                    p = 1;
                }
            }
        }
        return v;
    }
};