#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        vector<int> toposort;

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto &val : adj[i])
            {
                indegree[val]++;
            }
        }
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
            toposort.push_back(node);
            for (auto &val : adj[node])
            {
                indegree[val]--;
                if (indegree[val] == 0)
                {
                    q.push(val);
                }
            }
        }
        if (toposort.size() == V)
        {
            return false; // means it  is DAC
        }
        return true; /// means it is cyclic
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (auto dislike : prerequisites)
        {
            adj[dislike[0]].push_back(dislike[1]);
        }
        if (isCyclic(numCourses, adj))
        {
            return true;
        }
        return false;
    }
};
int main()
{
    return 0;
}