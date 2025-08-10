#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct TrieNode
{
    bool isEnd = false;
    string word;
    TrieNode *next[26] = {nullptr};
};

class Solution
{
    TrieNode *root = new TrieNode();
    vector<string> ans;
    int m = 0, n = 0;

    void insert(const string &w)
    {
        TrieNode *cur = root;
        for (char ch : w)
        {
            int idx = ch - 'a';
            if (!cur->next[idx])
                cur->next[idx] = new TrieNode();
            cur = cur->next[idx];
        }
        cur->isEnd = true;
        cur->word = w;
    }

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node)
    {
        char ch = board[r][c];
        int idx = ch - 'a';
        TrieNode *child = node->next[idx];
        if (!child)
            return;
        if (child->isEnd)
        {
            ans.push_back(child->word);
            child->isEnd = false;
        }
        board[r][c] = '#';
        static int dr[4] = {1, -1, 0, 0};
        static int dc[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; ++k)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] != '#')
            {
                char ch2 = board[nr][nc];
                TrieNode *next2 = child->next[ch2 - 'a'];
                if (next2)
                    dfs(board, nr, nc, child);
            }
        }
        board[r][c] = ch;
        bool leaf = !child->isEnd;
        for (int t = 0; t < 26 && leaf; ++t)
            if (child->next[t])
                leaf = false;
        if (leaf)
        {
            node->next[idx] = nullptr;
            delete child;
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        ans.clear();
        if (board.empty() || board[0].empty() || words.empty())
            return ans;
        m = (int)board.size();
        n = (int)board[0].size();
        for (const string &w : words)
            insert(w);
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (root->next[board[r][c] - 'a'])
                    dfs(board, r, c, root);
        return ans;
    }

    ~Solution()
    {
        function<void(TrieNode *)> clear = [&](TrieNode *n)
        {
            if (!n)
                return;
            for (TrieNode *ch : n->next)
                clear(ch);
            delete n;
        };
        clear(root);
    }
};