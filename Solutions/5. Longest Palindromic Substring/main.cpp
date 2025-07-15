#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int start = 0, maxim = 0;
        auto expandFromCenter = [&](int left, int right)
        {
            while (left >= 0 && right <= s.size() && s[left] == s[right])
            {
                --left;
                ++right;
            }
            return make_pair(left + 1, right - left - 1);
        };
        for (int i = 0; i < s.size(); ++i)
        {
            auto [start1, len1] = expandFromCenter(i, i);
            auto [start2, len2] = expandFromCenter(i, i + 1);
            if (len1 > maxim)
            {
                start = start1;
                maxim = len1;
            }
            if (len2 > maxim)
            {
                start = start2;
                maxim = len2;
            }
        }
        return s.substr(start, maxim);
    }
};