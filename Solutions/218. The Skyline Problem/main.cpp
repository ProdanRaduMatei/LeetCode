#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> events;
        for (auto &b : buildings)
        {
            int L = b[0], R = b[1], H = b[2];
            events.push_back({L, -H});
            events.push_back({R, H});
        }
        sort(events.begin(), events.end(), [](auto &a, auto &b)
             {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second; });
        multiset<int> heights = {0};
        int prevMax = 0;
        vector<vector<int>> res;
        for (auto &e : events)
        {
            int x = e.first, h = e.second;
            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));
            int curMax = *heights.rbegin();
            if (curMax != prevMax)
            {
                res.push_back({x, curMax});
                prevMax = curMax;
            }
        }
        return res;
    }
};