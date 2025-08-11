#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        if (word.size() > (size_t)m * n)
            return false;
        array<int, 256> freq{};
        for (auto &row : board)
            for (char c : row)
                ++freq[(unsigned char)c];
        array<int, 256> need{};
        for (char c : word)
            ++need[(unsigned char)c];
        for (int c = 0; c < 256; ++c)
            if (need[c] > freq[c])
                return false;
        if (freq[(unsigned char)word.front()] > freq[(unsigned char)word.back()])
            reverse(word.begin(), word.end());
        this->w = &word;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (board[r][c] == word[0] && dfs(board, r, c, 0))
                    return true;
        return false;
    }

private:
    int m = 0, n = 0;
    const string *w = nullptr;
    static constexpr int dr[4] = {1, -1, 0, 0};
    static constexpr int dc[4] = {0, 0, 1, -1};

    bool in(int r, int c) const
    {
        return (unsigned)r < (unsigned)m && (unsigned)c < (unsigned)n;
    }

    bool dfs(vector<vector<char>> &b, int r, int c, int idx)
    {
        if (idx == (int)w->size())
            return true;
        if (!in(r, c) || b[r][c] != (*w)[idx])
            return false;
        char saved = b[r][c];
        b[r][c] = '#';
        if (idx + 1 == (int)w->size())
        {
            b[r][c] = saved;
            return true;
        }
        char nextChar = (*w)[idx + 1];
        for (int k = 0; k < 4; ++k)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (in(nr, nc) && b[nr][nc] != '#' && b[nr][nc] == nextChar)
                if (dfs(b, nr, nc, idx + 1))
                {
                    b[r][c] = saved;
                    return true;
                }
        }
        b[r][c] = saved;
        return false;
    }
};