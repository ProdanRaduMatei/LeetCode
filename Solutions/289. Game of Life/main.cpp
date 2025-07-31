#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<int> dirs = {-1, 0, 1};

        auto countLiveNeighbors = [&](int i, int j)
        {
            int live = 0;
            for (int dx : dirs)
            {
                for (int dy : dirs)
                {
                    if (dx == 0 && dy == 0)
                        continue;
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        // Check original state using % 2
                        if (board[x][y] % 2 == 1)
                            live++;
                    }
                }
            }
            return live;
        };

        // Step 1: Encode next states
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int liveNeighbors = countLiveNeighbors(i, j);
                if (board[i][j] == 1)
                {
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                        board[i][j] = 2; // live -> dead
                }
                else
                {
                    if (liveNeighbors == 3)
                        board[i][j] = 3; // dead -> live
                }
            }
        }

        // Step 2: Finalize states
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};