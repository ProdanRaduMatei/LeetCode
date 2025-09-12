#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int best = 0;

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
                height[c] = (matrix[r][c] == '1') ? height[c] + 1 : 0;
            best = max(best, largestRectangleArea(height));
        }
        return best;
    }

private:
    int largestRectangleArea(const vector<int> &h)
    {
        stack<int> st;
        long long ans = 0;
        int n = h.size();
        for (int i = 0; i <= n; ++i)
        {
            int cur = (i == n) ? 0 : h[i];
            while (!st.empty() && h[st.top()] > cur)
            {
                int height = h[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long width = i - left - 1;
                ans = max(ans, 1LL * height * width);
            }
            st.push(i);
        }
        return (int)ans;
    }
};