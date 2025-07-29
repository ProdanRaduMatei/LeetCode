#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> idx;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (idx.count(val))
            return false;
        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!idx.count(val))
            return false;
        int last = nums.back();
        int pos = idx[val];
        nums[pos] = last;
        idx[last] = pos;
        nums.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */