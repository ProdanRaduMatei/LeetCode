#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string w = words[i];
            if (charToWord.count(c) && charToWord[c] != w)
                return false;
            if (wordToChar.count(w) && wordToChar[w] != c)
                return false;
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};