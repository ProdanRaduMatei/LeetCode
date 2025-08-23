#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int acc = 0;
        for (int x : nums)
            acc ^= x;
        return acc;
    }
};