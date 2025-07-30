#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        unordered_map<char, int> need;
        for (char c : t)
            ++need[c];
        int required = need.size();
        int formed = 0;
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;
        while (right < s.size())
        {
            char c = s[right];
            ++window[c];
            if (need.count(c) && window[c] == need[c])
                ++formed;
            while (left <= right && formed == required)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                --window[d];
                if (need.count(d) && window[d] < need[d])
                    --formed;
                ++left;
            }
            ++right;
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};