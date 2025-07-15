#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            if (lastSeen.count(c) && lastSeen[c] >= start)
                start = lastSeen[c] + 1;
            lastSeen[c] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};