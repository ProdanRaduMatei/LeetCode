#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct TrieNode
{
    bool isEnd = false;
    TrieNode *next[26] = {nullptr};
};

class WordDictionary
{
private:
    TrieNode *root;

    bool dfs(const string &word, int i, TrieNode *node) const
    {
        if (!node)
            return false;
        if (i == (int)word.size())
            return node->isEnd;
        char ch = word[i];
        if (ch == '.')
        {
            for (int c = 0; c < 26; ++c)
            {
                if (node->next[c] && dfs(word, i + 1, node->next[c]))
                    return true;
            }
            return false;
        }
        else
        {
            int idx = ch - 'a';
            return dfs(word, i + 1, node->next[idx]);
        }
    }

public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!node->next[idx])
                node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    bool search(const string &word) const
    {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */