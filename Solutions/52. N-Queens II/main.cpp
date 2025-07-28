#include <unordered_set>

using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        unordered_set<int> cols, diag1, diag2;
        int count = 0;
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n, unordered_set<int> &cols, unordered_set<int> &diag1, unordered_set<int> &diag2, int &count)
    {
        if (row == n)
        {
            count++;
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
                continue;
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            backtrack(row + 1, n, cols, diag1, diag2, count);
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};