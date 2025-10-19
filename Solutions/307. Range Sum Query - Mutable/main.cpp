#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums) : n(nums.size()), bit(n + 1, 0), arr(nums)
    {
        for (int i = 0; i < n; ++i)
            add(i + 1, arr[i]);
    }

    void update(int index, int val)
    {
        int delta = val - arr[index];
        arr[index] = val;
        add(index + 1, delta);
    }

    int sumRange(int left, int right)
    {
        return prefix(right + 1) - prefix(left);
    }

private:
    int n;
    vector<int> bit;
    vector<int> arr;

    void add(int idx, int delta)
    {
        while (idx <= n)
        {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int prefix(int idx) const
    {
        int res = 0;
        while (idx > 0)
        {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */