#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if (s.size() < totalLen)
            return result;
        unordered_map<string, int> wordMap;
        for (auto &w : words)
            wordMap[w]++;
        for (int i = 0; i < wordLen; i++)
        {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;
            for (int j = i; j + wordLen <= s.size(); j += wordLen)
            {
                string word = s.substr(j, wordLen);
                if (wordMap.find(word) != wordMap.end())
                {
                    seen[word]++;
                    count++;
                    while (seen[word] > wordMap[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == wordCount)
                    {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};