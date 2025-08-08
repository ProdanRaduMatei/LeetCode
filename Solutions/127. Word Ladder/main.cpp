#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!q.empty())
        {
            auto [word, level] = q.front();
            q.pop();
            for (int i = 0; i < word.size(); ++i)
            {
                for (auto c : "abcdefghijklmnopqrstuvwxyz")
                {
                    string next = word;
                    next[i] = c;
                    if (next == endWord)
                        return level + 1;
                    if (wordSet.count(next) && visited.find(next) == visited.end())
                    {
                        visited.insert(next);
                        q.push({next, level + 1});
                    }
                }
            }
        }
        return 0;
    }
};