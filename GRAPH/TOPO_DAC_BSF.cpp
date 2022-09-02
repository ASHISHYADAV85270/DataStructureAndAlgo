#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> topo_ans;
    for (int i = 0; i < V; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_ans.push_back(node);
        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    };

    return topo_ans;
}
int main()
{
    return 0;
}