#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
class Solution
{
public:
    bool isBipartite(int node, vector<int> &vis, vector<int> adj[], unordered_map<int, bool> &m)
    {
        queue<pair<int, bool>> q;
        m[node] = true;
        vis[node] = 1;
        q.push({node, true});
        while (!q.empty())
        {
            int val = q.front().first;
            int color = q.front().second;
            q.pop();
            for (auto &it : adj[val])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    m[it] = !color;
                    q.push({it, !color});
                }
                else
                {
                    if (m[it] == color)
                    {
                        return false;
                    }
                }
            }
        };
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        unordered_map<int, bool> m;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (isBipartite(i, vis, adj, m) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
*/
class Solution
{
public:
    bool biparitecheck(vector<vector<int>> &graph, vector<int> &color, int node)
    {
        if (color[node] == -1)
        {
            color[node] = 1;
        }
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto &val : graph[x])
            {
                if (color[val] == -1)
                {
                    color[val] = 1 - color[x];
                    q.push(val);
                }
                else if (color[val] == color[x])
                {
                    return false;
                }
            }
        };

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1)
            {
                if (biparitecheck(graph, color, i) == false)
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