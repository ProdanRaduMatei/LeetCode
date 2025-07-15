#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int maximum = 0;
        while (l < r)
        {
            long long curr = min(height[l], height[r]) * (r - l);
            if (curr > maximum)
                maximum = curr;
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return maximum;
    }
};