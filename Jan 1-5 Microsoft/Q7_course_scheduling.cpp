#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    bool checkCycle(int node, vector<int> graph[], vector<int> &vis, vector<int> &dfsVis)
    {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, graph, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it])
                return true;
        }

        dfsVis[node] = 0;
        return false;
    }

    bool isCyclic(int nodes, vector<int> graph[])
    {
        vector<int> vis(nodes, 0), dfsVis(nodes, 0);

        for (int i = 0; i < nodes; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, graph, vis, dfsVis))
                    return true;
            }
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> graph[numCourses];

        for (auto it : prerequisites)
            graph[it[0]].push_back(it[1]);

        return !isCyclic(numCourses, graph);
    }
};

int main()
{

    return 0;
}