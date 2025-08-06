#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        auto getCoord = [&](int num)
        {
            int r = n - 1 - (num - 1) / n;
            int c = (num - 1) % n;
            if ((n - 1 - r) % 2 == 1)
                c = n - 1 - c;
            return pair<int, int>(r, c);
        };
        vector<int> visited(n * n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        int moves = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n * n)
                    return moves;
                for (int dice = 1; dice <= 6; ++dice)
                {
                    int next = curr + dice;
                    if (next > n * n)
                        break;
                    auto [r, c] = getCoord(next);
                    if (board[r][c] != -1)
                        next = board[r][c];
                    if (!visited[next])
                    {
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};