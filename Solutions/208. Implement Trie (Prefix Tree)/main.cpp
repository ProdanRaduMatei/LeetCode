#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct TrieNode
{
    bool isEnd;
    TrieNode *next[26];

    TrieNode() : isEnd(false)
    {
        std::fill(std::begin(next), std::end(next), nullptr);
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26)
                continue;
            if (node->next[idx] == nullptr)
                node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    bool search(const string &word) const
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26)
                return false;
            node = node->next[idx];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }

    bool startsWith(const string &prefix) const
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26)
                return false;
            node = node->next[idx];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */