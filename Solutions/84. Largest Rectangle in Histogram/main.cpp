#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        long long best = 0;
        int n = heights.size();
        for (int i = 0; i <= n; ++i)
        {
            int cur = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > cur)
            {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long width = i - left - 1;
                best = max(best, width * h);
            }
            st.push(i);
        }
        return (int)best;
    }
};