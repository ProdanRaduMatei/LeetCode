#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        int leftProduct = 1;
        for (int i = 0; i < n; ++i)
        {
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return answer;
    }
};