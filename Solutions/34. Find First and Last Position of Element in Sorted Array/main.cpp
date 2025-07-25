#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
            if (nums[mid] == target)
                ans = mid;
        }
        return ans;
    }

    int findLast(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
            if (nums[mid] == target)
                ans = mid;
        }
        return ans;
    }
};