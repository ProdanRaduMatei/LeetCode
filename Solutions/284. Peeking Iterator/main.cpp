#include <iostream>
#include <vector>

using namespace std;

class Iterator
{
    struct Data
    {
        vector<int> nums;
        size_t index;
    } *data;

public:
    Iterator(const vector<int> &nums)
    {
        data = new Data{nums, 0};
    }

    Iterator(const Iterator &iter) { data = iter.data; }

    virtual ~Iterator() {}
    int next()
    {
        return data->nums[data->index++];
    }

    bool hasNext() const
    {
        return data->index < data->nums.size();
    }
};

class PeekingIterator : public Iterator
{
    bool hasPeeked;
    int peekedValue;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums), hasPeeked(false) {}
    int peek()
    {
        if (!hasPeeked)
        {
            peekedValue = Iterator::next();
            hasPeeked = true;
        }
        return peekedValue;
    }

    int next()
    {
        if (hasPeeked)
        {
            hasPeeked = false;
            return peekedValue;
        }
        return Iterator::next();
    }

    bool hasNext() const
    {
        return hasPeeked || Iterator::hasNext();
    }
};