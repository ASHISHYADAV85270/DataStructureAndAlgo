#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
class Solution
{
public:
    bool checkcylic(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto &val : adj[node])
        {
            if (!vis[val])
            {
                if (checkcylic(val, adj, vis, dfsvis))
                {
                    return true;
                }
            }
            else if (dfsvis[val])
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> dfsvis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (checkcylic(i, adj, vis, dfsvis))
            {
                return true;
            }
        }
        return false;
    }
}; */

class Solution
{
public:
    bool cyclecheck(vector<int> adj[], vector<int> &vis, vector<int> &dfsvis, int node)
    {
        vis[node] = 1;
        dfsvis[node] = 1;

        for (auto &it : adj[node])
        {
            if (vis[it] == 0)
            {
                if (cyclecheck(adj, vis, dfsvis, it) == true)
                {
                    return true;
                }
            }
            else if (dfsvis[it] == 1)
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (auto dislike : prerequisites)
        {
            adj[dislike[0]].push_back(dislike[1]);
        }
        vector<int> vis(numCourses, 0), dfsvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
            {
                if (cyclecheck(adj, vis, dfsvis, i) == true)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}