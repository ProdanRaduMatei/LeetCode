#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        if (valueDiff < 0)
            return false;
        unordered_map<long long, long long> bucket;
        long long size = (long long)valueDiff + 1;
        for (int i = 0; i < nums.size(); i++)
        {
            long long num = (long long)nums[i];
            long long id = getBucketId(num, size);
            if (bucket.count(id))
                return true;
            if (bucket.count(id - 1) && abs(num - bucket[id - 1]) <= valueDiff)
                return true;
            if (bucket.count(id + 1) && abs(num - bucket[id + 1]) <= valueDiff)
                return true;
            bucket[id] = num;
            if (i >= indexDiff)
            {
                long long oldId = getBucketId(nums[i - indexDiff], size);
                bucket.erase(oldId);
            }
        }
        return false;
    }

private:
    long long getBucketId(long long x, long long size)
    {
        return x >= 0 ? x / size : ((x + 1) / size - 1);
    }
};