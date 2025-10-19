#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
    vector<vector<long long>> pref;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        pref.assign(m + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            long long rowsum = 0;
            for (int j = 0; j < n; ++j)
            {
                rowsum += matrix[i][j];
                pref[i + 1][j + 1] = pref[i][j + 1] + rowsum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        long long ans = pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
        return static_cast<int>(ans);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */