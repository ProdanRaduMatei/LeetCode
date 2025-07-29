#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while (i < n)
        {
            int lineLen = words[i].size();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth)
            {
                lineLen += 1 + words[j].size();
                j++;
            }
            int spaces = maxWidth - lineLen;
            int wordCount = j - i;
            string line;
            if (j == n || wordCount == 1)
            {
                line = words[i];
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                int totalChars = 0;
                for (int k = i; k < j; k++)
                    totalChars += words[k].size();
                int spaceSlots = wordCount - 1;
                int spaceEach = (maxWidth - totalChars) / spaceSlots;
                int extra = (maxWidth - totalChars) % spaceSlots;
                for (int k = i; k < j - 1; k++)
                {
                    line += words[k];
                    line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                    if (extra > 0)
                        extra--;
                }
                line += words[j - 1];
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};