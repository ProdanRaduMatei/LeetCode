#include <vector>

using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &state)
    {
        if (state[node] == 1)
            return false;
        if (state[node] == 2)
            return true;
        state[node] = 1;
        for (int neighbor : graph[node])
            if (!dfs(neighbor, graph, state))
                return false;
        state[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (auto &pre : prerequisites)
            graph[pre[1]].push_back(pre[0]);
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (state[i] == 0)
                if (!dfs(i, graph, state))
                    return false;
        return true;
    }
};