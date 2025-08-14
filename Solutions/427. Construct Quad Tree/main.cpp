#include <vector>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node *build(const vector<vector<int>> &g, int r, int c, int size)
    {
        bool same = true;
        int firstVal = g[r][c];
        for (int i = r; i < r + size && same; ++i)
            for (int j = c; j < c + size; ++j)
                if (g[i][j] != firstVal)
                {
                    same = false;
                    break;
                }
        if (same)
            return new Node(firstVal == 1, true);
        int half = size / 2;
        Node *topLeft = build(g, r, c, half);
        Node *topRight = build(g, r, c + half, half);
        Node *bottomLeft = build(g, r + half, c, half);
        Node *bottomRight = build(g, r + half, c + half, half);
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};